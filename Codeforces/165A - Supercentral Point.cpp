#include <bits/stdc++.h>
using namespace std;
int tr[2005][2005];
int lowbit(int x) {
	return x & (-x);
}
int query(int x,int y) {
	int sum = 0;
	for (int i=x;i>=1;i-=lowbit(i))
		for (int j=y;j>=1;j-=lowbit(j)) sum += tr[i][j];
	return sum;
}
void insert(int x,int y) {
	for (int i=x;i<=2004;i+=lowbit(i))
		for (int j=y;j<=2004;j+=lowbit(j)) tr[i][j] ++;
}
struct Pos {
	int x,y;
}p[205];
int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%d%d",&p[i].x,&p[i].y);
		p[i].x += 1002;
		p[i].y += 1002;
		insert(p[i].x,p[i].y);
	}
	int cnt = 0;
	for (int i=0;i<n;i++) {
		int x = p[i].x;
		int y = p[i].y;
		int up = query(x,2004) - query(x-1,2004) - query(x,y) + query(x-1,y);
		int down = query(x,y-1) - query(x-1,y-1);
		int left = query(x-1,y) - query(x-1,y-1);
		int right = query(2004,y) - query(x,y) - query(2004,y-1) + query(x,y-1);
		//printf("%d %d %d %d\n",up,down,left,right);
		if (up > 0 && down > 0 && left > 0 && right > 0) cnt ++;
	}
	printf("%d\n",cnt);
	return 0;
}
