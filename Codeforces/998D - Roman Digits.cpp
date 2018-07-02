/*
#include <bits/stdc++.h>
using namespace std;
long long solve(long long n) {
	map <long long,bool> mem;
	long long ans = 0;
	for (long long a=0;a<=n;a++) {
		for (long long b=0;b<=n-a;b++) {
			for (long long c=0;c<=n-a-b;c++) {
				long long  d = n - a - b - c;
				long long sum = a + 5 * b + 10 * c + 50 * d;
				if (!mem[sum]) {
					mem[sum] = true;
					ans ++;
				}
			}
		}
	}
	return ans;
}
int main() {
	for (int i=1;i<=1000;i++) {
		cout << i << "\t" << solve(i) << endl;
	}
	return 0;
}
195	9308
196	9357
197	9406
198	9455
199	9504
200	9553
201	9602
*/
#include <bits/stdc++.h>
using namespace std;
long long ans[12] = {0,4,10,20,35,56,83,116,155,198,244,292};
int main() {
	long long n;
	cin >> n;
	if (n > 11) cout << ans[11] + (n-11) * 49 << endl;
	else cout << ans[n] << endl;
	return 0;
}