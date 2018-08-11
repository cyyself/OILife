#include <bits/stdc++.h>
using namespace std;
vector <long long> zys;
int main() {
	long long q;
	cin >> q;
	long long tmp = q;
	long long m = sqrt(tmp) + 0.5;
	for (long long i=2;i<=m;i++) {
		while (tmp % i == 0) {
			tmp /= i;
			zys.push_back(i);
		}
	}
	if (tmp > 1) zys.push_back(tmp);
	if (zys.size() <= 1) cout << "1\n0\n";//这个数是质数或者0
	else {
		if (zys.size() == 2) cout << "2\n";
		else {
			long long ans = 1;
			for (int i=zys.size()-1;i>=2;i--) ans *= zys[i];
			cout << "1\n" << q / ans << endl;
		}
	}
	return 0;
}
