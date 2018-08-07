#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int d[305][305];
int tmp[305];
int main() {
	int n,m;
	while (scanf("%d%d",&n,&m) == 2) {
		memset(d,0x3f,sizeof(d));
		for (int i=1;i<=n;i++) d[i][i] = 0;
		while (m--) {
			int num;
			scanf("%d",&num);
			for (int i=0;i<num;i++) {
				scanf("%d",&tmp[i]);
				for (int j=0;j<i;j++) {
					d[tmp[i]][tmp[j]] = 1;
					d[tmp[j]][tmp[i]] = 1;
				}
			}
		}
		for (int k=1;k<=n;k++)
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++) d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
		int ans = 0x7fffffff;
		for (int i=1;i<=n;i++) {
			int sum = 0;
			for (int j=1;j<=n;j++) sum += d[i][j];
			sum *= 100;
			sum /= n - 1;
			ans = min(ans,sum);
		}
		printf("%d\n",ans);//题目要求的不是四舍五入，用%0.0lf会WA
	}
	return 0;
}
