#include <bits/stdc++.h>
using namespace std;
int cnt[10];
int rem[10];
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	long long mod = 1;
	for (int i=1;i<=k;i++) mod *= 10;
	for (int i=1;i<=n;i++) {
		int x = i;
		while (x % 2 == 0) {
			cnt[2] ++;
			x /= 2;
		}
		while (x % 5 == 0) {
			cnt[5] ++;
			x /= 5;
		}
	}
	int suf = min(cnt[2],cnt[5]);
	rem[2] = suf;
	rem[5] = suf;
	long long ans = 1;
	for (int i=1;i<=n;i++) {
		int x = i;
		while (x % 2 == 0 && rem[2]) {
			rem[2] --;
			x /= 2;
		}
		while (x % 5 == 0 && rem[5]) {
			rem[5] --;
			x /= 5;
		}
		ans *= x;
		ans %= mod;
	}
	vector <char> out;
	while (ans) {
		out.push_back('0' + (ans % 10));
		ans /= 10;
	}
	while (out.size() < k) out.push_back('0');
	reverse(out.begin(),out.end());
	for (auto c:out) printf("%c",c);
	printf(" %d\n",suf);
	return 0;
}
