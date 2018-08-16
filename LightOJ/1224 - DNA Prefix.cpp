#include <bits/stdc++.h>
using namespace std;
int num[256];
struct node {
	int cnt;
	int ch[4];
}tr[2500005];
int ncnt;
void insert(char *s) {
	int len = strlen(s);
	int cur = 0;
	for (int i=0;i<len;i++) {
		int v = num[s[i]];
		if (tr[cur].ch[v] == 0) {
			tr[cur].ch[v] = ++ncnt;
			memset(&tr[ncnt],0,sizeof(node));
		}
		cur = tr[cur].ch[v];
		tr[cur].cnt ++;
	}
}

int ans;
void dfs(int cur,int dep) {
	ans = max(ans,dep*tr[cur].cnt);
	for (int i=0;i<4;i++) if (tr[cur].ch[i]) {
		dfs(tr[cur].ch[i],dep+1);
	}
}
char s[55];
int main() {
	num['A'] = 0;
	num['T'] = 1;
	num['C'] = 2;
	num['G'] = 3;
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		ans = 0;
		ncnt = 0;
		memset(&tr[0],0,sizeof(node));
		int n;
		scanf("%d",&n);
		while (n--) {
			scanf("%s",s);
			insert(s);
		}
		dfs(0,0);
		printf("Case %d: %d\n",c,ans);
	}
	return 0;
}
