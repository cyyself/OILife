#include <bits/stdc++.h>
using namespace std;
char a[100005][11];
long long cnt[11];
long long ans;
long long w[25];
void workb(int pos) {
	for (int i=1;i<=10;i++) {
		int len = strlen(a[pos]);
		int wpos = 0;
		for (int j=len-1;j>=0;j--) {
			ans += (cnt[i] * (long long)(a[pos][j]-'0') * w[wpos]) % 998244353LL;
			ans %= 998244353LL;
			if (wpos <= i * 2 - 2) wpos += 2;
			else wpos += 1;
		}
	}
}
void worka(int pos) {
	for (int i=1;i<=10;i++) {
		int len = strlen(a[pos]);
		int wpos = 1;
		for (int j=len-1;j>=0;j--) {
			ans += (cnt[i] * (long long)(a[pos][j]-'0') * w[wpos]) % 998244353LL;
			ans %= 998244353LL;
			if (wpos <= i * 2 - 3) wpos += 2;
			else wpos += 1;
		}
	}
}
int main() {
	w[0] = 1;
	for (int i=1;i<25;i++) {
		w[i] = w[i-1] * 10LL;
		w[i] %= 998244353LL;
	}
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%s",a[i]);
		cnt[strlen(a[i])] ++;
	}
	for (int i=0;i<n;i++) {
		worka(i);
		workb(i);
	}
	cout << ans << endl;
	return 0;
}
