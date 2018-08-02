#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int ti[25];
bool exist_m1[205][55];//exist[i][j]，代表在i时间，j站台
bool exist_m2[205][55];
int f[205][55];
int main() {
	int n;
	int cnt = 0;
	while (scanf("%d",&n) == 1 && n) {
		memset(f,0x3f,sizeof(f));
		memset(exist_m1,false,sizeof(exist_m1));
		memset(exist_m2,false,sizeof(exist_m2));
		int t;
		scanf("%d",&t);
		for (int i=0;i<n-1;i++) scanf("%d",&ti[i]);//间隔
		//init {
		int m1;
		scanf("%d",&m1);
		for (int i=0;i<m1;i++) {
			int time;
			scanf("%d",&time);
			for (int j=0;j<n;j++) {
				if (time > t) break;
				exist_m1[time][j] = true;
				time += ti[j];
			}
		}
		int m2;
		scanf("%d",&m2);
		for (int i=0;i<m2;i++) {
			int time;
			scanf("%d",&time);
			for (int j=n-1;j>0;j--) {
				if (time > t) break;
				exist_m2[time][j] = true;
				time += ti[j-1];//这里注意和上面不一样
			}
		}
		f[t][n-1] = 0;
		//init }
		for (int i=t-1;i>=0;i--) {
			for (int j=0;j<n;j++) {
				f[i][j] = f[i+1][j] + 1;//原地停留
				if (j < n-1 && exist_m1[i][j] && i + ti[ j ] <= t) //这一秒有m1在此处停下来
					f[i][j] = min(f[i][j],f[i+ti[ j ]][j+1]);//如果i+t[j]秒可以在j+1停留，那么i秒可以在j停留
				if (j > 0   && exist_m2[i][j] && i + ti[j-1] <= t) //这一秒有m2在此处停下来
					f[i][j] = min(f[i][j],f[i+ti[j-1]][j-1]);//果i+t[j-1]秒可以在j-1停留，那么i秒可以在j停留
			}
		}
		printf("Case Number %d: ",++cnt);
		if (f[0][0] >= INF) printf("impossible\n");//大于是因为可能从别的inf状态转移过来
		else printf("%d\n",f[0][0]);
	}
	return 0;
}
