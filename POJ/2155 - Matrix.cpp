#include <cstdio>
inline int lowbit(int x) {
	return x & (-x);
}
int n,q;
int arr[1005][1005];
inline int sum(int x,int y) {
	int ans = 0;
	for (register int i=x;i>=1;i-=lowbit(i))
		for (register int j=y;j>=1;j-=lowbit(j)) {
			ans ^= arr[i][j];
		}
	return ans;
}
inline void add(int x,int y) {
	for (register int i=x;i<=n;i+=lowbit(i)) 
		for (register int j=y;j<=n;j+=lowbit(j)) arr[i][j] ^= 1;
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		scanf("%d%d",&n,&q);
		n ++;
		for (register int i=1;i<=n;i++) for (register int j=1;j<=n;j++) arr[i][j] = 0;
		while (q --) {
			char o;
			scanf(" %c",&o);
			if (o == 'C') {
				int x_1,y_1,x_2,y_2;
				scanf("%d%d%d%d",&x_1,&y_1,&x_2,&y_2);
				add(x_1,y_1);
				add(x_1,y_2+1);
				add(x_2+1,y_1);
				add(x_2+1,y_2+1);
			}
			else {
				int x,y;
				scanf("%d%d",&x,&y);
				printf("%d\n",sum(x,y));
			}
		}
		printf("\n");
	}
	return 0;
}
