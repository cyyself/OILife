#include <cstdio>
#include <cstring>
using namespace std;
int stat[2][1<<20];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	int last,cur;
	stat[1][0] = 1;
	for (int i=0;i<n;i++) {
		last = (i & 1) ^ 1;
		cur = i & 1;
		memset(stat[cur],0,sizeof(stat[cur]));
		int p;
		scanf("%d",&p);
		while (p --) {
			int barn;
			scanf("%d",&barn);
			barn --;
			for (int j=1;j<(1<<m);j++) {
				if (j & (1 << barn) && __builtin_popcount(j) == i+1) {
					stat[cur][j] += stat[last][j^(1 << barn)];
				}
			}
		}
	}
	int ans = 0;
	for (int i=1;i<(1 << m);i++) {
		if (__builtin_popcount(i) == n) ans += stat[cur][i];
	}
	printf("%d\n",ans);
	return 0;
}
