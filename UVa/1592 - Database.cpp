#include <bits/stdc++.h>
using namespace std;
string s[10000][10];
string t;
int main() {
	int n,m;
	while (cin >> n >> m) {
		getline(cin,t);
		map <string,vector<int> > cnt[10];
		for (int i=0;i<n;i++) {
			getline(cin,t);
			string cur = "";
			int index = 0;
			for (int j=0;j<t.length();j++) {
				if (t[j] != ',') cur += t[j];
				else {
					cnt[index][cur].push_back(i);
					s[i][index++] = cur;
					cur = "";
				}
			}
			cnt[index][cur].push_back(i);
			s[i][index++] = cur;
		}
		bool ans = false;
		int c1,c2,r1,r2;
		for (c1=0;c1<m;c1++) {
			if (cnt[c1].size() >= n) continue;
			for (auto x:cnt[c1]) if (x.second.size() >= 2) {//找到相同的
				for (int i=0;i<x.second.size();i++) {
					for (int j=i+1;j<x.second.size();j++) {//找到一对c，有不同的r
						r1 = x.second[i];
						r2 = x.second[j];
						for (c2=c1+1;c2<m;c2++) {
							if (s[r1][c2] == s[r2][c2]) {
								ans = true;
								break;
							}
						}
						if (ans) break;
					}
					if (ans) break;
				}
				if (ans) break;
			}
			if (ans) break;
		}
		if (!ans) printf("YES\n");
		else printf("NO\n%d %d\n%d %d\n",r1+1,r2+1,c1+1,c2+1);
	}
	return 0;
}
