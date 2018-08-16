#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
using namespace std;
struct node {
	int virus;//病毒编号
	int next;//匹配不上时走的节点
	int ch[128];
}tr[200005];
bool vis[200005];
int ncnt = 0;
void insert(char *s,int num) {
	int cur = 0;
	int len = strlen(s);
	for (int i=0;i<len;i++) {
		int v = s[i];
		if (!tr[cur].ch[v]) tr[cur].ch[v] = ++ncnt;
		cur = tr[cur].ch[v];
	}
	tr[cur].virus = num;
}
void build_tree() {
	queue <int> q;//一定要广搜
	for (int i=0;i<128;i++) {
		if (tr[0].ch[i]) {
			tr[tr[0].ch[i]].next = 0;
			q.push(tr[0].ch[i]);
		}
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i=0;i<128;i++) {
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
bool ans[505];
bool getans(char *s) {
	bool exist = false;
	memset(ans,false,sizeof(ans));
	int len = strlen(s);
	int cur = 0;
	for (int i=0;i<len;i++) {
		int v = s[i];
		cur = tr[cur].ch[v];
		for (int j=cur;j;j=tr[j].next) {
			if (tr[cur].virus != 0) {
				exist = true;
				ans[tr[cur].virus] = true;
			}
		}
	}
	return exist;
}
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
char s[10005];
int main() {
	int n;
	scanf("%d",&n);
	cyy::gets(s);
	for (int i=1;i<=n;i++) {
		cyy::gets(s);
		insert(s,i);
	}
	build_tree();
	int m;
	scanf("%d",&m);
	cyy::gets(s);
	int ans_cnt = 0;
	for (int i=1;i<=m;i++) {
		cyy::gets(s);
		if (getans(s)) {
			printf("web %d:",i);
			ans_cnt ++;
			for (int j=1;j<=n;j++) if (ans[j]) printf(" %d",j);
			printf("\n");
		}
	}
	printf("total: %d\n",ans_cnt);
	return 0;
}
