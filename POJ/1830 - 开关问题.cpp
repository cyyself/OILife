#include <cstdio>
#include <cstring>
#include <algorithm>
using std::swap;
int s[35];
int a[35][35];
int n;
int gauss() {
	int free = 0;
	int id,i;
	for (id=i=1;i<=n;i++,id++) {
		int k = id;
		for (int j=id+1;j<=n;j++) if (a[j][i]) {
			k = j;
			break;
		}
		if (a[k][i] == 0) {
			free ++;
			id--;
			continue;
		}
		if (k != id) for (int j=i;j<=n+1;j++) swap(a[id][j],a[k][j]);
		for (int j=1;j<=n;j++) if (j != id && a[j][i]) {
			for (int k=i;k<=n+1;k++) a[j][k] ^= a[id][k];
		}
	}
	for (int i=id;i<=n;i++) if (a[i][n+1]) return -1;
	return free;
}
int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&s[i]);
		for (int i=1;i<=n;i++) {
			int ns;
			scanf("%d",&ns);
			if (ns != s[i]) a[i][n+1] = 1;
			a[i][i] = 1;
		}
		int i,j;
		while (scanf("%d%d",&i,&j) == 2 && (i || j)) a[j][i] = 1;
		int s = gauss();
		if (s == -1) printf("Oh,it's impossible~!!\n");
		else printf("%d\n",1<<s);
	}
	return 0;
}
