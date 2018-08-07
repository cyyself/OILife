#include <bits/stdc++.h>
using namespace std;
char s[100005];
int nxt[100005];
int len;
int getnext() {
	int ans = 0;
	int k = -1;
	nxt[0] = -1;
	for (int i=1;i<len;i++) {
		while (k != -1 && s[i] != s[k+1]) k = nxt[k];
		if (s[k+1] == s[i]) k ++;
		nxt[i] = k;
		ans = max(ans,k);
	}
	return ans;
}
int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		scanf("%s",s);
		len = strlen(s);
		getnext();
		if (nxt[len-1] == -1) printf("%d\n",len);
		else {
			int t = len - (nxt[len-1] + 1);
			if (len % t == 0) printf("0\n");
			else printf("%d\n",t-len%t);
		}
	}
	return 0;
}
