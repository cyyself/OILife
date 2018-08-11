#include <bits/stdc++.h>
using namespace std;
char s[100005];
char p[100005];
int cnt[26];
int cur[26];
bool check(int any) {
	int need = 0;
	for (int i=0;i<26;i++) if (cur[i] < cnt[i]) need += cnt[i] - cur[i];
	return need <= any;
}
int main() {
	scanf("%s%s",s,p);
	int plen = strlen(p);
	for (int i=0;i<plen;i++) if (p[i] != '?') cnt[p[i]-'a'] ++;
	int slen = strlen(s);
	if (plen > slen) {
		printf("0\n");
	}
	else {
		int any = 0;
		for (int i=0;i<plen;i++) {
			if (s[i] == '?') any ++;
			else cur[s[i]-'a'] ++;
		}
		int l = 0;
		int r = plen - 1;
		int ans = 0;
		while (r < slen) {
			if (check(any)) ans ++;
			if (s[l] == '?') any --;
			else cur[s[l]-'a'] --;
			if (r == slen - 1) break;
			l ++;
			r ++;
			if (s[r] == '?') any ++;
			else cur[s[r]-'a'] ++;	
		}
		printf("%d\n",ans);
	}
	return 0;
}
