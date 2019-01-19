#include <bits/stdc++.h>
using namespace std;
int deg[1005];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		deg[x] ++;
		deg[y] ++;
	}
	for (int i=1;i<=n;i++) {
		if (deg[i] == 0) {
			printf("%d\n",n-1);
			for (int j=1;j<=n;j++) {
				if (j == i) continue;
				printf("%d %d\n",i,j);
			}
			break;
		}
	}
	return 0;
}
