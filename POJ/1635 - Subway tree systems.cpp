#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
char s[3005];
string dfs(int x) {
	vector <string> ch;
	while (s[x] == '0') {
		string t = "("+dfs(x+1);
		ch.push_back(t);
		x += t.length();
	}
	sort(ch.begin(),ch.end());
	string ret = "";
	for (vector<string>::iterator it=ch.begin();it != ch.end();it ++) ret += *it;
	return ret + ")";
}
int main() {
	int t;
	scanf("%d",&t);
	while (t --) {
		scanf("%s",s);
		string t = dfs(0);
		scanf("%s",s);
		if (dfs(0) == t) puts("same");
		else puts("different");
	}
	return 0;
}
