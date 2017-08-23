#include <cstdio>
#include <algorithm>
#define INF 0x7fffffff
using namespace std;
int f[55][55];
int main() {
	/*
	f[i][j] = min(f[i][k]+f[k][j]+c[j]-c[i])
	其中f[i][j]是从第i个切割点到第j个切割点之间的最小费用
	我们通过枚举k来求出区间内切割的最小费用
	0<=i<n
	i<j<=n+1
	i<k<j
	除此之外我们在写程序时还要注意for循环的层次，因为我们使用f[i][k]和f[k][j]时必须保证已经求出解
	*/
	for(;;) {
		int l;
		int n;
		scanf("%d",&l);
		if (l == 0) break;
		scanf("%d",&n);
		int c[55];
		c[0] = 0;
		for (int i=1;i<=n;i++) scanf("%d",&c[i]);
		c[n+1] = l;
		for (int d=2;d<=n+1;d++) {//i和j之间的差值，从i到j的闭区间必须是3个数，因此d从2开始
			for (int i=0;i<=n+1-d;i++) {//由于j必须小于n+1，所以我们让i<=n+1-d
				int j = i + d;
				int MIN = INF;
				for (int k=i+1;k<j;k++) MIN = min(MIN,f[i][k]+f[k][j]+c[j]-c[i]);
}
				f[i][j] = MIN;
			}
		}
		printf("The minimum cutting is %d.\n",f[0][n+1]);
	}
	return 0;