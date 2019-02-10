#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
string s[15];
int cost[15][15];//cost[i][j]表示在字符串j的左边连接字符串i所需花费
int f[1<<15][15];
int n;

int dfs(int stat,int head) {
	if (stat == 0) return 0;
	if (__builtin_popcount(stat) == 1) return s[head].length();
	if (f[stat][head] != INF) return f[stat][head];
	for (int i=0;i<n;i++) if ((stat & (1 << i)) && i != head) {
		if (dfs(stat^(1<<head),i) + cost[head][i] < f[stat][head]) {
			f[stat][head] = dfs(stat^(1<<head),i) + cost[head][i];
		}
	}
	return f[stat][head];
}
string getans(int stat,int head) {
	if (__builtin_popcount(stat) == 1) return "";
	string nxt_s = "Z";
	int nxt;
	for (int i=0;i<n;i++) if ((stat & (1 << i)) && i != head) {
		if (dfs(stat^(1<<head),i) + cost[head][i] == f[stat][head]) {
			string t = s[i].substr(s[head].length()-cost[head][i]);
			if (t < nxt_s) {
				nxt_s = t;
				nxt = i;
			}
		}
	}
	return nxt_s + getans(stat^(1<<head),nxt);
}
int main() {
	int T;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++) {
		memset(f,0x3f,sizeof(f));
		memset(cost,0,sizeof(cost));
		scanf("%d",&n);
		for (int i=0;i<n;i++) cin >> s[i];
		for (int i=0;i<n;i++) for (int j=0;j<n;j++) {//预处理字符串存在包含的情况（WA了好久）
			if (i == j) continue;
			if (s[i].find(s[j]) != string::npos) {
				s[j] = s[i];
			}
		}
		sort(s,s+n);
		n = unique(s,s+n) - s;
		for (int i=0;i<n;i++) for (int j=0;j<n;j++) {//预处理字符串拼接的最小花费
			if (i == j) continue;
			int m = min(s[i].length(),s[j].length());
			for (int k=0;k<=m;k++) {
				if (s[i].substr(s[i].length()-k) == s[j].substr(0,k)) {
					cost[i][j] = s[i].length() - k;
				}
			}
		}
		int ans = 0x3f3f3f3f;
		string res = "";
		for (int i=0;i<n;i++) {
			if (dfs((1<<n)-1,i) < ans) {
				ans = f[(1<<n)-1][i];
				res = s[i]+getans((1<<n)-1,i);
			}
			else if (dfs((1<<n)-1,i) == ans) {
				res = min(res,s[i]+getans((1<<n)-1,i));
			}
		}
		printf("Scenario #%d:\n",cas);
		cout << res << endl << endl;
	}
	return 0;
}
