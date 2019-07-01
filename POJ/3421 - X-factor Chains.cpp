#include <cstdio>
#include <map>
using namespace std;
unsigned long long c[50][50];
int main() {
	c[0][0] = 1;
	for (int i=1;i<=30;i++) {
		c[i][0] = 1;
		c[i][i] = 1;
		for (int j=1;j<i;j++) c[i][j] = c[i-1][j] + c[i-1][j-1];
	}
	int x;
	while (scanf("%d",&x) == 1) {
		map <int,int> cnt;
		int tot = 0;
		for (int i=2;i*i<=x;i++) {
			while (x % i == 0) {
				x /= i;
				cnt[i] ++;
				tot ++;
			}
		}
		if (x != 1) {
			cnt[x] ++;
			tot ++;
		}
		long long cm  = tot;
		unsigned long long ans = 1;
		for (map<int,int>::iterator it=cnt.begin();it != cnt.end();it ++) {
			ans *= c[cm][it->second];
			cm -= it->second;
		}
		printf("%d %llu\n",tot,ans);
	}
	return 0;
}
