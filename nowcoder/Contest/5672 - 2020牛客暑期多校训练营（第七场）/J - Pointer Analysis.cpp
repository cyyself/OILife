#include <bits/stdc++.h>
using namespace std;
/*
编号规则：
A-Z:1-26
A.a-Z.z=27-702
a-z=703-728
a.a-a.z=729-1404
*/
const int maxn = 1405;
int ans[maxn],anslast[maxn];
int read(string s) {
	if (s.length() == 3) return 27 + 26 * (s[0]-'A') + (s[2]-'a');
	else return s[0]&32?703+s[0]-'a':1+s[0]-'A';
}
vector <pair<int,int> > edges;
vector <int> g[maxn];
bool inq[maxn];
bool spfa() {
	for (int i=1;i<maxn;i++) {
		anslast[i] = ans[i];
		ans[i] = 0;
	}
	queue <int> q;
	for (int i=703;i<=728;i++) {
		ans[i] = 1 << (i - 703);
		q.push(i);
		inq[i] = true;
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (auto v:g[u]) {
			if ((ans[v] | ans[u]) != ans[v]) {
				ans[v] |= ans[u];
				if (!inq[v]) {
					q.push(v);
					inq[v] = true;
				}
			}
		}
	}
	for (int i=1;i<maxn;i++) {
		if (ans[i] != anslast[i]) return true;
	}
	return false;
}
bool is_ch(int x) {
	return 27 <= x && x <= 702;
}
bool work() {
	for (int i=1;i<maxn;i++) g[i].clear();
	for (auto each:edges) {
		int u = each.first;
		int v = each.second;
		if (is_ch(u)) {
			for (int j=0;j<26;j++) if ((ans[1+(u-27)/26] >> j) & 1) {
				g[v].push_back(729 + 26 * j + (u - 27) % 26);
			}
		}
		else if (is_ch(v)) {
			for (int j=0;j<26;j++) if ((ans[1+(v-27)/26] >> j) & 1) {
				g[729 + 26 * j + (v - 27) % 26].push_back(u);
			}
		}
		else {
			g[v].push_back(u);
		}
	}
	return spfa();
}
int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		string u,eq,v;
		cin >> u >> eq >> v;
		edges.emplace_back(read(u),read(v));
	}
	while (work());
	for (int i=1;i<=26;i++) {
		printf("%c: ",'A'+i-1);
		for (int j=0;j<26;j++) if ((ans[i] >> j) & 1) printf("%c",'a'+j);
		printf("\n");
	}
	return 0;
}
