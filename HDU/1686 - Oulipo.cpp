#include <bits/stdc++.h>
using namespace std;
char w[10005];
int nxt[10005];
char t[1000005];
int n,m;
int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		scanf("%s%s",w,t);
		n = strlen(w);
		m = strlen(t);
		int k = -1;
		nxt[0] = -1;
		for (int i=1;i<n;i++) {
			while (k != -1 && w[k+1] != w[i]) k = nxt[k];
			if (w[k+1] == w[i]) k ++;
			nxt[i] = k;
		}
		k = -1;
		int ans = 0;
		for (int i=0;i<m;i++) {
			while (k != -1 && w[k+1] != t[i]) k = nxt[k];
			if (w[k+1] == t[i]) k ++;
			if (k == n - 1) ans ++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
