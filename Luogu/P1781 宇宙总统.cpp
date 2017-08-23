#include <iostream>
using namespace std;
bool comp(string a, string b) {
	if (a.length() > b.length()) return true;
	if (a.length() == b.length()) {
		for (int i=0;i<a.length();i++) if (a[i] > b[i]) {
			return true;
		}
		else {
			if (a[i] < b[i]) return false;
		}
	}
	return false;
}
int main() {
	int n;
	cin >> n;
	string max = "0";
	int maxn = 0;
	for (int i=1;i<=n;i++) {
		string t;
		cin >> t;
		if (comp(t,max)) {
			maxn = i;
			max = t;
		}
	}
	cout << maxn << endl << max << endl;
	return 0;
}