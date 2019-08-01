#include <bits/stdc++.h>
using namespace std;
int vcnt;
vector <int> num[26];
vector <int> g[100005];
char s[100005];
int deg[100005];
char a[100005];
char seq[100005];
int curnum[100005];
bool vis[26];
int topocnt;
void topo_sort() {
	queue <int> q;
	for (int i=1;i<=vcnt;i++) if (deg[i] == 0) q.push(i);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		seq[++topocnt] = a[u];
		for (auto v:g[u]) {
			deg[v] --;
			if (deg[v] == 0) q.push(v);
		}
	}
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	vcnt = 0;
	m = m * (m - 1) / 2;
	for (int i=0;i<m;i++) {
		char c[3];
		int len;
		scanf("%s%d",c,&len);
		for (int j=0;j<len;j++) scanf(" %c",&s[j]);
		int cnt[26];
		memset(cnt,0,sizeof(cnt));
		if (!vis[c[0]-'a']) for (int j=0;j<len;j++) {
			if (s[j] != c[0]) continue;
			num[c[0]-'a'].push_back(++vcnt);
			a[vcnt] = c[0];
		}
		if (!vis[c[1]-'a']) for (int j=0;j<len;j++) {
			if (s[j] != c[1]) continue;
			num[c[1]-'a'].push_back(++vcnt);
			a[vcnt] = c[1];
		}
		for (int j=0;j<len;j++) {
			if (cnt[s[j]-'a'] >= num[s[j]-'a'].size()) {
				printf("-1\n");
				return 0;
			}
			curnum[j] = num[s[j]-'a'][cnt[s[j]-'a']];
			cnt[s[j]-'a'] ++;
		}
		for (int j=1;j<len;j++) {
			g[curnum[j-1]].push_back(curnum[j]);
			deg[curnum[j]]++;
		}
		if (cnt[c[0]-'a'] != num[c[0]-'a'].size() || cnt[c[1]-'a'] != num[c[1]-'a'].size()) {
			printf("-1\n");
			return 0;
		}
		vis[c[0]-'a'] = true;
		vis[c[1]-'a'] = true;
	}
	if (vcnt != n) printf("-1\n");
	else {
		topo_sort();
		if (topocnt == vcnt) {
			for (int i=1;i<=vcnt;i++) printf("%c",seq[i]);
			printf("\n");
		}
		else printf("-1\n");
	}
	return 0;
}
