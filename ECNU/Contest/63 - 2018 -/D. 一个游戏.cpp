#include <bits/stdc++.h>
int in[105],out[105];
bool g[105][105];
int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		memset(g,false,sizeof(g));
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		int n;
		scanf("%d",&n);
		while (n--) {
			int a,b;
			scanf("%d%d",&a,&b);
			g[a][b] = true;
		}
		for (int i=1;i<=100;i++)
			for (int j=1;j<=100;j++) 
				if (g[i][j] && i != j) {
					out[i] ++;
					in[j] ++;
				}
		bool ok = true;
		for (int i=1;i<=100;i++) {
			if ( (in[i] > 0 && out[i] > 0) || out[i] >= 2) {
				ok = false;
				break;
			}
		}
		if (ok) printf("Lucky dxw!\n");
		else printf("Poor dxw!\n");
	}
	return 0;
}
