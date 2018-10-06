#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int ls[2005];
int  a[2005];
int  f[2005];//f[j]表示当前最高为j的时候的cost
int n;
int lscnt;
int cal() {
	memset(f,0,sizeof(f));
	for (int i=0;i<n;i++){
		int mincost = INF;
		for (int j=0;j<lscnt;j++) {
			mincost = min(mincost,f[j]);//在小于等于它的里面找一个最小的
			f[j] = mincost + abs(a[i]-ls[j]);//这里增加的cost
		}
	}
	int ans = INF;
	for (int i=0;i<lscnt;i++) ans = min(ans,f[i]);
	return ans;
}
int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%d",&a[i]);
		ls[i] = a[i];
	}
	sort(ls,ls+n);
	lscnt = unique(ls,ls+n)-ls;
	int ans = cal();
	reverse(a,a+n);
	ans = min(ans,cal());
	printf("%d\n",ans);
	return 0;
}
