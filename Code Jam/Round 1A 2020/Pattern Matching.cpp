#include <bits/stdc++.h>
using namespace std;
char s[105];
bool isprefix(string &a,string &b) {//a is prefix of b
	if (a.length() > b.length()) return false;
	for (int i=0;i<a.length();i++) if (a[i] != b[i]) return false;
	return true;
}
bool issuffix(string a,string b) {
	if (a.length() > b.length()) return false;
	for (int i=a.length()-1;i>=0;i--) if (a[i] != b[b.length()-(a.length()-i)]) return false;
	return true;
}
bool cmp(string &a,string &b) {
	return a.length() > b.length();
}
vector <string> split(string s) {
	vector <string> sp;
	string tmp;
	for (int j=0;j<s.length();j++) {
		if (s[j] == '*') {
			sp.push_back(tmp);
			tmp = "";
		}
		else tmp.push_back(s[j]);
	}
	sp.push_back(tmp);
	return sp;
}
int main() {
	int T;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++) {
		int n;
		scanf("%d",&n);
		vector <string> s;
		string eq = "*";
		bool ok = true;
		for (int i=0;i<n;i++) {
			string tmp;
			cin >> tmp;
			s.push_back(tmp);
			if (tmp.find("*") == string::npos) {
				if (eq != "*") {
					if (eq != tmp) ok = false;
				}
				else eq = tmp;
			}
		}
		if (ok) {
			if (eq == "*") {
				vector <string> prefix,suffix,center;
				for (int i=0;i<n;i++) {
					vector <string> sp = split(s[i]);
					prefix.push_back(sp[0]);
					suffix.push_back(sp[sp.size()-1]);
					for (int j=1;j<sp.size()-1;j++) center.push_back(sp[j]);
				}
				sort(prefix.begin(),prefix.end(),cmp);
				sort(suffix.begin(),suffix.end(),cmp);
				string pre = "", suf = "";
				if (prefix.size()) pre = prefix[0];
				if (suffix.size()) suf = suffix[0];
				for (auto x:prefix) if (!isprefix(x,pre)) ok = false;
				for (auto x:suffix) if (!issuffix(x,suf)) ok = false;
				if (ok) {
					printf("Case #%d: ",cas);
					cout << pre;
					for (auto x:center) cout << x;
					cout << suf;
					printf("\n");
				}
				else printf("Case #%d: *\n",cas);
			}
			else {
				for (int i=0;i<n && ok;i++) {
					vector <string> sp = split(s[i]);
					int ptr = 0;
					for (auto x:sp) {
						auto pos = eq.find(x,ptr);
						if (pos != string::npos) ptr = pos + x.length();
						else {
							ok = false;
							break;
						}
					}
				}
				if (ok) {
					printf("Case #%d: ",cas);
					cout << eq;
					printf("\n");
				}
				else printf("Case #%d: *\n",cas);
			}
		}
		else printf("Case #%d: *\n",cas);
	}
	return 0;
}
