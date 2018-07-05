#include <bits/stdc++.h>
using namespace std;
int n;
int a[1005];
vector <int> cost[1005];
int cal(int h) {//h=>qs需要达到的票数
	int ans = 0;
	int curh = cost[n].size();
	vector <int> backup;
	for (int i=1;i<n;i++) {
		int sz = cost[i].size();//WA了好久qwq 直接取vector的size是个unsigned long，减成负数会gg
		for (int j=0;j<sz;j++) {//使它减小到h-1，若本来就小于h-1则直接放入备选
			if (j < sz-(h-1) ) {
				ans += cost[i][j];
				curh ++;
			}
			else backup.push_back(cost[i][j]);
		}
	}
	sort(backup.begin(),backup.end());
	for (int i=0;i<backup.size() && curh < h;i++) {
		ans += backup[i];
		curh ++;
	}
	return ans;
}

int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		for (int i=1;i<=n;i++) cost[i].clear();
		for (int i=1;i<n;i++) scanf("%d",&a[i]);
		a[n] = n;//没用
		for (int i=1;i<n;i++) {
			int t;
			scanf("%d",&t);
			cost[a[i]].push_back(t);
		}
		cost[n].push_back(0);
		for (int i=1;i<n;i++) sort(cost[i].begin(),cost[i].end());
		int ans = 0x3fffffff;
		for (int i=1;i<n;i++) ans = min(ans,cal(i));//枚举高度求最小cost
		printf("%d\n",ans);
	}
	return 0;
}
