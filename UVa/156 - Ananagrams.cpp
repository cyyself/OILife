#include <bits/stdc++.h>
using namespace std;
map <string,int> mem;
void insert(string s) {
	for (int i=0;i<s.length();i++) s[i] |= 32;
	sort(s.begin(),s.end());
	mem[s] ++;
}
int query(string s) {
	for (int i=0;i<s.length();i++) s[i] |= 32;
	sort(s.begin(),s.end());
	return mem[s];
}
string t;
vector <string> dic;
int main() {
	while (cin >> t && t != "#") {
		insert(t);
		dic.push_back(t);
	}
	sort(dic.begin(),dic.end());
	for (auto x:dic) {
		if (query(x) <= 1) cout << x << endl;
	}
	return 0;
}
