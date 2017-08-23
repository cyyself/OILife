#include <cstdio>
#include <cstring>
struct Trie {
	int index;
	Trie *ch[26];
	Trie():index(-1) {
		memset(ch,0,sizeof(ch));
	}
}root;
int cnt = 0;
int GetHash(char *s) {
	int len = strlen(s);
	Trie *n = &root;
	for (int i=0;i<len;i++) {
		if (n->ch[s[i]-'a'] == NULL) n->ch[s[i]-'a'] = new Trie;
		n = n->ch[s[i]-'a'];
		if (i == len - 1 && n->index == -1) return n->index = cnt++; 
	}
	return n->index;
}
char a[15];
char b[15];
int deg[500005];
int fa[500005];
int find(int x) {
	if (fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}
inline void uni(int x,int y) {
	fa[find(x)] = find(y);
}
int main() {
	for (int i=0;i<500005;i++) fa[i] = i;
	while(scanf("%s%s",a,b) == 2) {
		int x = GetHash(a);
		int y = GetHash(b);
		deg[x]++;
		deg[y]++;
		uni(x,y);
	}
	int anc = find(0);//定义0为根节点
	int js = 0;
	for (int i=0;i<cnt;i++) {
		if (deg[i] % 2) js ++;
		if (find(i) != anc) {
			//存在多个欧拉回路
			printf("Impossible\n");
			return 0;
		}
	}
	if (js == 0 || js == 2) printf("Possible\n");
	else printf("Impossible\n");
	return 0;
}