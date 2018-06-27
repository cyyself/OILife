#include <bits/stdc++.h>
using namespace std;

struct Tr{
	Tr *ch[26];//child
	int cnt;
	int last;
	Tr() {
		memset(ch,0,sizeof(ch));
		cnt = 0;
		last = 0;
	}
}root;
inline void insert(char *s,Tr *node) {
	if (*s == '\0') {
		node->cnt ++;
	}
	else {
		if (node->ch[*s-'a'] == NULL) node->ch[*s-'a'] = new Tr;
		insert(s+1,node->ch[*s-'a']);
	}
}
inline int query(char *s,Tr *node,int curquery) {
	int ret = 0;
	if (node->last != curquery) {
		ret += node->cnt;
		node->last = curquery;
	}
	if (*s != '\0' && node->ch[*s-'a'] != NULL) ret += query(s+1,node->ch[*s-'a'],curquery);
	return ret;
}

char s[20005][15];
int n;

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%s",s[i]);
		insert(s[i],&root);
	}
	int ans = 0;
	for (int i=1;i<=n;i++) {
		int len = strlen(s[i]);
		for (int j=0;j<=len-1;j++) {
			ans += query(&s[i][j],&root,i);
		}
		ans --;//除去匹配了自己的情况
	}
	printf("%d\n",ans);
	return 0;
}
