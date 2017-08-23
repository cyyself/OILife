#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		printf("Case %d:",c);
		int n,t;
		scanf("%d%d",&n,&t);
		int s[55];
		int nt = 0;
		for (int i=0;i<n;i++) {
			scanf("%d",&s[i]);
			nt += s[i];
		}
		nt ++;//nt多加一秒，因为背包不能完全装满
		t = min(nt,t);//因为t最大值达到了10^9，而歌曲最多50首，每首最多180秒，最多不过9000秒，因此我们为了防止开太大数组爆内存这样做即可
		int f[10005] = {0};//存储最大歌曲数
		int f2[10005] = {0};//存储最长唱歌时间
		for (int i=0;i<n;i++) for (int j=t-1;j>=s[i];j--) {
			if (f[j-s[i]] + 1 > f[j] || (f[j-s[i]] + 1 == f[j] && f2[j-s[i]] + s[i] >= f2[j]) ) {
				f[j] = f[j-s[i]] + 1;
				f2[j] = f2[j-s[i]] + s[i];
			}
		}
		printf(" %d %d\n",f[t-1]+1,f2[t-1]+678);
	}
	return 0;
}