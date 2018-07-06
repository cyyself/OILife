#include <bits/stdc++.h>
int cnt[26];
char s[100005];
int main() {
	int T;
	scanf("%d",&T);
	for (int i=1;i<=T;i++) {
		memset(cnt,0,sizeof(cnt));
		int l;
		scanf("%d",&l);
		scanf("%s",s);
		for (int j=0;j<l;j++) cnt[s[j]-'a'] ++;
		bool ans = true;
		for (int j=0;j<26;j++) if (cnt[j] > 1) {
			ans = false;
			break;
		}
		if (ans) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}