#include <bits/stdc++.h>
using namespace std;
int T,n,tmp,ans,len,a,b,c;
int main() {
	cin >> T;
	for (int cas=0;cas<T;cas++) {
		cin >> n;
		tmp = n;
		ans = 0;
		len = 0;
		while (tmp > 0) {
			ans += tmp % 10;
			tmp /= 10;
			len ++;
		}
		a = (n / 100) % 10;
		b = (n / 10) % 10;
		c = n % 10;
		while (len < n) {
			if (c == 0) break;
			tmp = ((a + b) * c) % 10;
			ans += tmp;
			a = b;
			b = c;
			c = tmp;
			len ++;
		}
		cout << "case #" << cas << ":\n" << ans << endl;
	}
	return 0;
}
