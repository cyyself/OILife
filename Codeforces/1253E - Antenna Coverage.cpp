//奶一波这个代码能AC
#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
#define x first
#define y second
int f[81][100001];//前i个天线，覆盖到前缀j位置，所需要的最小花费
pair <int,int> s[81];
bool cmp(pair<int,int> &x,pair<int,int> &y) {
	return x.x + x.y < y.x + y.y;
}
int main() {
	memset(f,0x3f,sizeof(f));
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) {
		scanf("%d%d",&s[i].x,&s[i].y);
		f[i][0] = 0;
	}
	f[0][0] = 0;
	sort(s+1,s+n+1,cmp);
	for (int i=1;i<=n;i++) {
		int j = 0;
		for (int j=0;j<=max(0,max(s[i].x-s[i].y-1,m-(s[i].x+s[i].y)));j++) {
			int lneed = s[i].x - s[i].y - j - 1;
			int cur = j;
			if (lneed > 0) cur += f[i-1][lneed];
			if (cur >= inf) continue;
			f[i][min(m,s[i].x+s[i].y+j)] = min(f[i][min(m,s[i].x+s[i].y+j)],cur);
		}
		f[i][m] = min(f[i][m],f[i-1][m]);
		for (int j=m-1;j>=0;j--) f[i][j] = min(min(f[i][j],f[i-1][j]),f[i][j+1]);
	}
	printf("%d\n",f[n][m]);
	return 0;
}
