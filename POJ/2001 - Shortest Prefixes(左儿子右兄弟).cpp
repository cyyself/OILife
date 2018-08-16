#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct Trie{
	int cnt;
	char c;
	Trie *son,*bro;
	Trie():cnt(0),c(0),son(NULL),bro(NULL){};
}root;
char dic[1005][25];
char ans[25];
int cnt = 0;
Trie *GotoBrother(Trie *n,char c) {
	//??????
	Trie *cur = n;
	while(cur->c != c) {
		if (cur->bro == NULL) {
			cur->bro = new Trie;
			cur = cur->bro;
			cur->c = c;
		}
		else cur = cur->bro;
	}return cur;
}
void insert(char *s) {
	Trie *n = &root;
	int len = strlen(s);
	for (int i=0;i<len;i++) {
		if (n->son == NULL) n->son = new Trie;
		n = n->son;
		n = GotoBrother(n,s[i]);
		n->cnt ++;
	}
}
void query(char *s) {
	memset(ans,0,sizeof(ans));
	Trie *n = &root;
	int len = strlen(s);
	for (int i=0;i<len;i++) {
		if (n->son == NULL) n->son = new Trie;
		n = n->son;
		n = GotoBrother(n,s[i]);
		ans[i] = s[i];
		if (n->cnt == 1) return;
	}
}
int main() {
	//freopen("1.in","r",stdin);
	while(scanf("%s",dic[cnt]) == 1) {
		insert(dic[cnt]);
		cnt ++;
	}
	for (int i=0;i<cnt;i++) {
		query(dic[i]);
		printf("%s %s\n",dic[i],ans);
	}
	return 0;
}
