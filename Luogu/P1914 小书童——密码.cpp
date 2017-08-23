#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	n = n % 26;
	for (int i=0;i<s.length();i++) {
		int t = s[i];
		t += n;
		if (t > 'z') t = t - 26;
		s[i] = (char)t;
	}
	cout << s << endl;
	return 0;
}