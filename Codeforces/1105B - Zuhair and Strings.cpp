#include <bits/stdc++.h>
using namespace std;
char s[200005];
int cnt[26];
int pre[200005];
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++) {
		if (s[i] == s[i-1]) pre[i] = pre[i-1] + 1;
		else pre[i] = 1;
		if (pre[i] >= k) {
			pre[i] -= k;
			cnt[s[i]-'a'] ++;
		}
	}
	int ans = 0;
	for (int i=0;i<26;i++) ans = max(ans,cnt[i]);
	printf("%d\n",ans);
	return 0;
}
