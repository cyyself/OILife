#include <bits/stdc++.h>
using namespace std;
vector < pair<int,int> > ans;
int gcd(int a,int b) {
	if (b == 0) return a;
	return gcd(b,a%b);
}
int main() {
	int n,m;
	cin >> n >> m;
	if (m < n - 1) {
		printf("Impossible\n");
		return 0;
	}
	for (int i=2;i<=n && ans.size() < m;i++) ans.push_back(make_pair(1,i));
	for (int i=2;i<=n && ans.size() < m;i++) {
		for (int j=2;j<i && ans.size() < m;j++) {
			if (gcd(i,j) == 1) ans.push_back(make_pair(i,j));
		}
	}
	if (ans.size() < m) printf("Impossible\n");
	else {
		printf("Possible\n");
		int cnt = 0;
		for (auto a:ans) {
			cout << a.first << " " << a.second << endl;
		}
	}
	return 0;
}
