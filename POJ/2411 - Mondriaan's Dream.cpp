#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool judge(int stat) {
	while (stat) {
		if (stat & 1) {
			stat >>= 1;
			if (!(stat & 1)) return false;
		}
		stat >>= 1;
	}
	return true;
}
bool valid[1<<11];
int s[150];
int validcnt;
long long f[11][1<<11];
int main() {
	for (int i=0;i<(1<<11);i++) if (judge(i)) {
		valid[i] = true;
		s[validcnt ++] = i;
	}
	//printf("%d\n",validcnt);
	int n,m;
	while (scanf("%d%d",&n,&m) == 2 && n && m) {
		if (n < m) swap(n,m);
		memset(f,0,sizeof(f));
		int scnt = upper_bound(s,s+validcnt,(1<<m)-1) - s;
		for (int j=0;j<scnt;j++) f[0][s[j]] = 1;
		for (int i=1;i<n;i++) {
			for (int j=0;j<(1<<m);j++)
				for (int k=0;k<(1<<m);k++) {
					if ( (j|k) != (1 << m) - 1) continue;
					if (!valid[j&k]) continue;
					f[i][j] += f[i-1][k];
				}
		}
		printf("%lld\n",f[n-1][(1<<m)-1]);
	}
	return 0;
}
