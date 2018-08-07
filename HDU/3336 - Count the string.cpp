#include <bits/stdc++.h>
using namespace std;
char s[200005];
int n;
int nxt[200005];
int f[200005];
void getnext() {
	int k = -1;
	nxt[1] = 0;
	for (int i=2;i<=n;i++) {
		while (k != 0 && s[k+1] != s[i]) k = nxt[k];
		if (s[k+1] == s[i]) k++;
		nxt[i] = k;
	}
}
int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		scanf("%s",s+1);
		int ans = 0;
		getnext();
		memset(f,0,sizeof(f));
		for (int i=1;i<=n;i++) {
			f[i] += (f[nxt[i]]+1) % 10007;
			ans = (ans + f[i]) % 10007;
		}
		printf("%d\n",ans);
	}
	return 0;
}
