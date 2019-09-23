#include <bits/stdc++.h>
using namespace std;
int cnt[205];
void read(vector <string> &res,char *s) {
	string tmp = "";
	for (int i=0;s[i];i++) {
		if (s[i] == ' ') {
			res.push_back(tmp);
			tmp = "";
		}
		else tmp += s[i];
	}
	res.push_back(tmp);
}
bool is_digit(char c) {
	return c >= '0' && c <= '9';
}
bool avail(string &s) {
	if (s.length() == 0) return false;
	if (s.length() == 1 && s[0] == '0') return true;//不能有前导0，但是可以为0
	if (s[0] == '0' || !is_digit(s[0])) return false;
	if (!is_digit(s[s.length()-1])) return false;
	for (auto c:s) if (!is_digit(c)) return false;
	return true;
}
string only_digit(string &s) {
	string ret = "";
	for (auto c:s) {
		if (is_digit(c)) ret += c;
	}
	return ret;
}
vector <string> s[205];
char tmp[1005];
vector <string> out;
bool ban[205];
int main() {
	int n = 0;
	while (cin.getline(tmp,1005)) {
		n ++;
		read(s[n],tmp);
	}
	for (int i=1;i<=n;i++) {
		for (int j=ban[i];j<s[i].size();j++) {
			if (j == s[i].size() -1 && is_digit(s[i][j][s[i][j].length()-1])) {
				int k = i + 1;
				while (k <= n && is_digit(s[k][0][0])) {
					ban[k] = true;
					s[i][j] += s[k][0];
					if (s[k].size() != 1 || !is_digit(s[k][0][s[k][0].length()-1])) break;
					k ++;
				}
			}
			if (avail(s[i][j])) {
				out.push_back(only_digit(s[i][j]));
				cnt[i] ++;
			}
		}
	}
	for (int i=0;i<out.size();i++) cout << out[i] << ( (i == out.size() - 1)?'\n':' ');
	for (int i=1;i<=n;i++) cout << cnt[i] << '\n';
	return 0;
}
