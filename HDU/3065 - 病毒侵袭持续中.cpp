#include <bits/stdc++.h>
using namespace std;
namespace cyy {
	void gets(char *s) {
		char c = getchar();
		while (c != '\n') {
			*s = c;
			s ++;
			c = getchar();
		}
		*s = '\0';
	}
}
struct node {
	int virus;
	int next;//匹配不上时走的节点
	int ch[26];
}tr[100005];
int ncnt;
void insert(char *s,int virus) {
	int cur = 0;
	int len = strlen(s);
	for (int i=0;i<len;i++) {
		int v = s[i] - 'A';
		if (!tr[cur].ch[v]) {
			tr[cur].ch[v] = ++ncnt;
			memset(&tr[ncnt],0,sizeof(node));
		}
		cur = tr[cur].ch[v];
	}
	tr[cur].virus = virus;
}
void build_tree() {
	queue <int> q;//一定要广搜
	for (int i=0;i<26;i++) {
		if (tr[0].ch[i]) {
			tr[tr[0].ch[i]].next = 0;
			q.push(tr[0].ch[i]);
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
			else {
				v = tr[tr[u].next].ch[i];
			}
		}
	}
}
int cnt[1005];
void getans(char *s) {
	int len = strlen(s);
	int cur = 0;
	for (int i=0;i<len;i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			cur = tr[cur].ch[s[i]-'A'];
		}
		else cur = 0;
		for (int j=cur;j;j=tr[j].next) {
			cnt[tr[j].virus] ++;
		}
	}
}
char virusname[1005][55];
char s[2000005];
int main() {
	int n;
	while (scanf("%d",&n) == 1) {
		ncnt = 0;
		memset(tr,0,sizeof(tr));
		memset(cnt,0,sizeof(cnt));
		cyy::gets(s);
		for (int i=1;i<=n;i++) {
			cyy::gets(&virusname[i][0]);
			insert(&virusname[i][0],i);
		}
		build_tree();
		cyy::gets(s);
		getans(s);
		for (int i=1;i<=n;i++) {
			if (cnt[i] > 0) printf("%s: %d\n",virusname[i],cnt[i]);
		}
	}
	return 0;
}
