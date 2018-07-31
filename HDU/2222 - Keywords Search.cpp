#include <bits/stdc++.h>
using std::queue;
struct node {
	int cnt;
	int ch[26];
	int next;
	bool vis;
}tr[500005];
int ncnt = 0;
char tmp[1000005];
void insert(char *s) {
	int len = strlen(s);
	int u = 0;
	for (int i=0;i<len;i++) {
		int &v = tr[u].ch[s[i]-'a'];
		if (!v) v = ++ncnt;
		u = v;
	}
	tr[u].cnt ++;
}
void build_tree() {
	int u = 0;
	queue <int> q;
	for (int i=0;i<26;i++) {
		int &v = tr[0].ch[i];
		if (v) {
			tr[v].next = 0;
			q.push(v);
		}
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i=0;i<26;i++) {
			int &v = tr[u].ch[i];
			if (v) {
				tr[v].next = tr[tr[u].next].ch[i];
				q.push(v);
			}
			else v = tr[tr[u].next].ch[i];
		}
	}
}
int getans(char *s) {
	int len = strlen(s);
	int u = 0;
	int ans = 0;
	for (int i=0;i<len;i++) {
		u = tr[u].ch[s[i]-'a'];
		for (int j=u;j != 0 && !tr[j].vis;j=tr[j].next) {
			ans += tr[j].cnt;
			tr[j].vis = true;
		}
	}
	return ans;
}
int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		for (int i=0;i<=ncnt;i++) memset(&tr[i],0,sizeof(node));
		ncnt = 0;
		int n;
		scanf("%d",&n);
		while (n--) {
			scanf("%s",tmp);
			insert(tmp);
		}
		build_tree();
		scanf("%s",tmp);
		printf("%d\n",getans(tmp));
	}
	return 0;
}
