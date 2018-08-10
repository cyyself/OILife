#include <cstdio>
#include <cstring>
int a[1005][1005];
int n;
inline int lowbit(int x) {
	return x & (-x);
}
inline void add(int x,int y,int d) {
	for (int i=x;i<=n;i+=lowbit(i)) for (int j=y;j<=n;j+=lowbit(j)) a[i][j] += d;
}
inline int sum(int x,int y) {
	int ret = 0;
	for (int i=x;i>=1;i-=lowbit(i)) for (int j=y;j>=1;j-=lowbit(j)) ret += a[i][j];
	return ret;
}
int main() {
	int X;
	scanf("%d",&X);
	while (X--) {
		int t;
		memset(a,0,sizeof(a));
		scanf("%d%d",&n,&t);
		n ++;
		while (t--) {
			char op[5];
			scanf("%s",op);
			if (op[0] == 'C') {
				int x_1,y_1,x_2,y_2;
				scanf("%d%d%d%d",&x_1,&y_1,&x_2,&y_2);
				add(x_1,y_1,1);
				add(x_2+1,y_2+1,-1);
				add(x_1,y_2+1,-1);
				add(x_2+1,y_1,1);//被多减了一次，所以再加回去（容斥原理）
				
			}
			else {
				int x,y;
				scanf("%d%d",&x,&y);
				printf("%d\n",sum(x,y)%2);
			}
		}
		printf("\n");
	}
	return 0;
}
