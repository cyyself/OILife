#include <bits/stdc++.h>
using namespace std;
int ti[55];
int f[10005];//记录唱歌数量，虽然T很大，但是n只有到50(为啥我2年后再写一遍这道题没想到这个)
int g[10005];//记录唱歌时间
int main() {
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		printf("Case %d: ",c);
		int n,t;
		scanf("%d%d",&n,&t);
		int sum = 0;
		for (int i=0;i<n;i++) {
			scanf("%d",&ti[i]);
			sum += ti[i];
		}
		int t_max = min(t-1,sum);
		for (int i=0;i<n;i++)
			for (int j=t_max;j>=ti[i];j--) {
				if (f[j-ti[i]] + 1 > f[j] || (f[j-ti[i]] + 1 == f[j] && g[j-ti[i]] + ti[i] > g[j])) {
					f[j] = f[j-ti[i]]+1;
					g[j] = g[j-ti[i]] + ti[i];
				}
			}
		printf("%d %d\n",f[t_max]+1,g[t_max]+678);
	}
	return 0;
}
