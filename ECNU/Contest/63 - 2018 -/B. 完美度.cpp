#include <bits/stdc++.h>
using std::sort;
char s[1000005];
int cnt[26];
int main() {
	scanf("%s",s);
	int len = strlen(s);
	for (int i=0;i<len;i++) {
		if (s[i] & 32) s[i] ^= 32;
		cnt[s[i]-65] ++;
	}
	sort(cnt,cnt+26);
	int ans = 0;
	for (int i=25;i>=0;i--) ans += (i+1)*cnt[i];
	printf("%d\n",ans);
	return 0;
}
