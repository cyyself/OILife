#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
string s[10];
int nxt[65];
void getnext(string p) {
	int k = -1;
	nxt[0] = -1;
	for (int i=1;i<p.length();i++) {
		while (k != -1 && p[i] != p[k+1]) k = nxt[k];
		if (p[i] == p[k+1]) k++;
		nxt[i] = k;
	}
}
bool exist(string t,string p) {
	int k = -1;
	for (int i=0;i<t.length();i++) {
		while (k != -1 && t[i] != p[k+1]) k = nxt[k];
		if (t[i] == p[k+1]) k++;
		if (k == p.length() - 1) return true;
	}
	return false;
}
int main() {
	int n;
	cin >> n;
	while (n--) {
		string ans = "";
		int m;
		scanf("%d",&m);
		for (int i=0;i<m;i++) cin >> s[i];
		for (int len=s[0].length();len>=3;len--) {
			for (int i=0;i<=s[0].length()-len;i++) {
				string p = s[0].substr(i,len);
				getnext(p);
				bool flag = true;
				for (int j=1;j<m;j++) if (!exist(s[j],p)) {
					flag = false;
					break;
				}
				if (flag) {
					if (ans == "") ans = p;
					else ans = min(ans,p);
				}
			}
			if (ans != "") break;
		}
		if (ans == "" || ans.length() < 3) cout << "no significant commonalities" << endl;
		else cout << ans << endl;
	}
	return 0;
}
