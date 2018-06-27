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
};
int curinsert;
inline void insert(char *s,Tr *node) {
	if (*s == '\0') {
		node->cnt ++;
	}
	else {
		if (node->ch[*s-'a'] == NULL) node->ch[*s-'a'] = new Tr;
		insert(s+1,node->ch[*s-'a']);
	}
}
int curquery;
int ans = 0;
inline void query(char *s,Tr *node) {
	if (node->last != curquery) {
		ans += node->cnt;
		node->last = curquery;
	}
	if (*s != '\0' && node->ch[*s-'a'] != NULL) query(s+1,node->ch[*s-'a']);
}
Tr root;
char s[20005][15];
int n;

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%s",s[i]);
		curinsert = i;
		insert(s[i],&root);
	}
	for (int i=1;i<=n;i++) {
		curquery = i;
		int len = strlen(s[i]);
		for (int j=0;j<=len-1;j++) {
			query(&s[i][j],&root);
		}
		ans --;
	}
	printf("%d\n",ans);
	return 0;
}
