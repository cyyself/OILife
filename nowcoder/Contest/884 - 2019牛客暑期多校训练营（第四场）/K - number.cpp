#include <bits/stdc++.h>
using namespace std;
int cnt[3];
char s[100005];
int main() {
	scanf("%s",s+1);
	int len = strlen(s+1);
	int sum = (s[1] - '0') % 3;
	long long ans = (s[1] == '0');
	cnt[0] ++;
	cnt[sum] ++;
	for (int i=2;i<=len;i++) {
		sum += s[i] - '0';
		sum %= 3;
		if (s[i] == '0') {
			if (s[i-1] == '0') ans += cnt[sum];
			else ans ++;
		}
		cnt[sum] ++;
	}
	printf("%lld\n",ans);
	return 0;
}
