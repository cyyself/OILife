#include <bits/stdc++.h>
using namespace std;
char s[100005];
int main() {
	int n;
	cin >> n;
	cin >> s;
	sort(s,s+n);
	cout << s << endl;
	return 0;
}
