#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m;
long long f[2][1<<11];
bool mark[1<<11];
inline bool judge(int i) {
	while (i) {
		if (i & 1) {
			i >>= 1;
			if (!(i & 1)) return false;
		}
		i >>= 1;
	}
	return true;
}
int main() {
	while (scanf("%d%d",&n,&m) == 2 && (n||m)) {
		if (n < m) swap(n,m);
		//n > m
		memset(mark,false,sizeof(mark));
		memset(f[0],0,sizeof(f[0]));
		for (int j=0;j<(1<<m);j++) if (judge(j)) {
			f[0][j] = 1;
			mark[j] = true;
		}
		for (int i=1;i<n;i++) {
			memset(f[i&1],0,sizeof(f[i&1]));
			for (int j=0;j<(1<<m);j++) 
				for (int k=0;k<(1<<m);k++) {
					if ( (j|k) != (1<<m) - 1) continue;
					if (!mark[j&k]) continue;
					f[i&1][j] += f[(i&1)^1][k];
				}
		}
		printf("%lld\n",f[(n&1)^1][(1<<m)-1]);
	}
	return 0;
}