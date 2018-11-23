#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
map <string,int> mem;
double f[30][30];
int main() {
	int n;
	int cas = 0;
	while (scanf("%d",&n) == 1 && n) {
		for (int i=0;i<n;i++) {
			string t;
			cin >> t;
			mem[t] = i;
		}
		memset(f,0,sizeof(f));
		for (int i=0;i<n;i++) f[i][i] = 1;
		int m;
		scanf("%d",&m);
		while (m --) {
			string a,b;
			double r;
			cin >> a >> r >> b;
			f[mem[a]][mem[b]] = max(r,f[mem[a]][mem[b]]);
		}
		for (int k=0;k<n;k++)
			for (int i=0;i<n;i++)
				for (int j=0;j<n;j++) f[i][j] = max(f[i][j],f[i][k] * f[k][j]);
		bool flag = false;
		for (int i=0;i<n;i++) if (f[i][i] > 1) flag = true;
		printf("Case %d: %s\n",++cas,flag?"Yes":"No");
	}
	return 0;
}
