#include <bits/stdc++.h>
using namespace std;
struct DATA {
	int x,y;
	long long val;
	friend bool operator < (const DATA &a,const DATA &b) {
		return a.val < b.val;
	}
}a[1000005];
int getblock(int x,int y,long long sz) {
	sz >>= 1;
	if (y <= sz) {
		if (x <= sz) return 0;
		else return 1;
	}
	else {
		if (x <= sz) return 3;
		else return 2;
	}
}
long long query(int x,int y,long long sz,int in,int out) {
	if (sz == 1) return 1;
	int seq[4] = {in,-1,-1,out};
	seq[1] = ((in - 1 + 4) % 4 == out)?(in + 1 + 4) % 4:(in - 1 + 4) % 4;
	seq[2] = ((out - 1 + 4) % 4 == in)?(out + 1 + 4) % 4:(out - 1 + 4) % 4;
	long long sum = 0;
	for (int i=0;i<4;i++) {
		if (getblock(x,y,sz) == seq[i]) break;
		sum += (sz >> 1) * (sz >> 1);
	}
	if (getblock(x,y,sz) == seq[1] || getblock(x,y,sz) == seq[2]) {
		int nx = x;
		int ny = y;
		if (nx > sz/2) nx -= sz/2;
		if (ny > sz/2) ny -= sz/2;
		return sum + query(nx,ny,sz>>1,in,out);
	}
	else if (getblock(x,y,sz) == seq[0]) {
		int nx = x;
		int ny = y;
		if (nx > sz/2) nx -= sz/2;
		if (ny > sz/2) ny -= sz/2;
		return sum + query(nx,ny,sz>>1,in,(out+2) % 4);
	}
	else {
		int nx = x;
		int ny = y;
		if (nx > sz/2) nx -= sz/2;
		if (ny > sz/2) ny -= sz/2;
		return sum + query(nx,ny,sz>>1,(in+2)%4,out);
	}
}
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	long long sz = 1 << k;
	for (int i=0;i<n;i++) {
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].val = query(a[i].x,a[i].y,sz,0,3);
	}
	sort(a,a+n);
	for (int i=0;i<n;i++) {
		printf("%d %d\n",a[i].x,a[i].y);
	}
	return 0;
}
