#include <bits/stdc++.h>
using namespace std;
int n,w,k;
map <int,int> cnt;
vector <int> yi;
int f[105][105];//f[i][j]表示前i个x轴平行线，用了k次移动后，清理掉的辣鸡量
int main() {
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		scanf("%d%d%d",&n,&w,&k);
		for (map<int,int>::iterator iter=cnt.begin();iter != cnt.end();) cnt.erase(iter++);
		yi.clear();
		for (int i=0;i<n;i++) {
			int x,y;
			scanf("%d%d",&x,&y);
			cnt[y] ++;
			yi.push_back(y);
		}
		sort(yi.begin(),yi.end());
		yi.erase(unique(yi.begin(),yi.end()),yi.end());
		for (int i=0;i<yi.size();i++) {
			int cur = 0;
			int pos;
			for (pos=i;pos>=0 && yi[pos] >= yi[i] - w;pos--) cur += cnt[yi[pos]];
			for (int j=0;j<=k;j++) {
				if (j == 0) f[i][j] = 0;
				else {
					f[i][j] = max(cur,f[i][j-1]);
					if (i != 0 && pos >= 0) for (int p=pos;p>=0;p--) f[i][j] = max(f[i][j],f[p][j-1]+cur);
				}
			}
		}
		int ans = 0;
		for (int i=0;i<yi.size();i++) ans = max(ans,f[i][k]);
		printf("Case %d: %d\n",c,ans);
	}
	return 0;
}
