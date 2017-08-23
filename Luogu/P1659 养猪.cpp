#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
struct pig{
	int a;
	int p;
}p[1005];
int n,k;
int f[1005][1005];
bool comp(const pig &a,const pig &b) {
	if (a.p > b.p || (a.p == b.p && a.a > b.a) ) return true;
	return false;
}
int main() {
	scanf("%d%d",&n,&k);
	k = min(n,k);
	for (int i=1;i<=n;i++) scanf("%d",&p[i].a);
	for (int i=1;i<=n;i++) scanf("%d",&p[i].p);
	sort(p+1,p+n+1,comp);
	//printf("---------\n");
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=k;j++) {
			//决定今天杀不杀这只猪
			f[i][j] = max(f[i-1][j],f[i-1][j-1]+max(p[i].a-p[i].p*(j-1),0));
			//printf("%d ",f[i][j]);
		}
		//printf("\n");
	}
	//printf("---------\n");
	int ans = 0;
	for (int i=1;i<=k;i++) ans = max(ans,f[n][i]);
	printf("%d\n",ans);
	return 0;
}