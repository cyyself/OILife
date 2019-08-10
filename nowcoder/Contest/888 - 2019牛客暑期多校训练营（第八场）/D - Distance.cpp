#include <bits/stdc++.h>
using namespace std;
const int ninf = 0x80000000;
const int inf = 0x3f3f3f3f;
int n,m,h;
struct BIT {
	int arr[100005];
	inline int lowbit(int x) {
		return x & (-x);
	}
	inline int id(int x,int y,int z) {
		return (x-1) * m * h + (y-1) * h + (z-1);
	}
	void init() {
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				for (int k=1;k<=h;k++) arr[id(i,j,k)] = ninf;
	}
	void update(int x,int y,int z,int val) {
		for (int i=x;i<=n;i+=lowbit(i)) 
			for (int j=y;j<=m;j+=lowbit(j))
				for (int k=z;k<=h;k+=lowbit(k)) {
					arr[id(i,j,k)] = max(arr[id(i,j,k)],val);
				}
	}
	int query(int x,int y,int z) {
		int ans = -inf;
		for (int i=x;i>=1;i-=lowbit(i))
			for (int j=y;j>=1;j-=lowbit(j))
				for (int k=z;k>=1;k-=lowbit(k)) {
					ans = max(ans,arr[id(i,j,k)]);
				}
		return ans;
	}
}t[8];
int main() {
	int q;
	scanf("%d%d%d%d",&n,&m,&h,&q);
	for (int i=0;i<8;i++) t[i].init();
	while (q --) {
		int op,x,y,z;
		scanf("%d%d%d%d",&op,&x,&y,&z);
		if (op == 1) {
			t[0].update(  x  ,  y  ,  z  ,   x   +   y   +   z   );
			t[1].update(  x  ,m-y+1,  z  ,   x   +(m-y+1)+   z   );
			t[2].update(n-x+1,m-y+1,  z  ,(n-x+1)+(m-y+1)+   z   );
			t[3].update(n-x+1,  y  ,  z  ,(n-x+1)+   y   +   z   );
			t[4].update(  x  ,  y  ,h-z+1,   x   +   y   +(h-z+1));
			t[5].update(  x  ,m-y+1,h-z+1,   x   +(m-y+1)+(h-z+1));
			t[6].update(n-x+1,m-y+1,h-z+1,(n-x+1)+(m-y+1)+(h-z+1));
			t[7].update(n-x+1,  y  ,h-z+1,(n-x+1)+   y   +(h-z+1));
		}
		else {
			int ans = inf;
			ans = min(ans,   x   +   y   +   z   -t[0].query(  x  ,  y  ,  z  ));
			ans = min(ans,   x   +(m-y+1)+   z   -t[1].query(  x  ,m-y+1,  z  ));
			ans = min(ans,(n-x+1)+(m-y+1)+   z   -t[2].query(n-x+1,m-y+1,  z  ));
			ans = min(ans,(n-x+1)+   y   +   z   -t[3].query(n-x+1,  y  ,  z  ));
			ans = min(ans,   x   +   y   +(h-z+1)-t[4].query(  x  ,  y  ,h-z+1));
			ans = min(ans,   x   +(m-y+1)+(h-z+1)-t[5].query(  x  ,m-y+1,h-z+1));
			ans = min(ans,(n-x+1)+(m-y+1)+(h-z+1)-t[6].query(n-x+1,m-y+1,h-z+1));
			ans = min(ans,(n-x+1)+   y   +(h-z+1)-t[7].query(n-x+1,  y  ,h-z+1));
			printf("%d\n",ans);
		}
	}
	return 0;
}
