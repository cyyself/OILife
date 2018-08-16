//G++会MLE，用C++
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
struct Trie {
	int cnt;
	Trie* ch[26];
}root;
int ncnt;
void insert(char *s) {
	int len = strlen(s);
	Trie *cur = &root;
	for (int i=0;i<len;i++) {
		int v = s[i] - 'a';
		if (cur->ch[v] == NULL) {
			cur->ch[v] = new Trie;
			memset(cur->ch[v],0,sizeof(Trie));
		}
		cur = cur->ch[v];
		cur->cnt ++;
	}
}
int query(char *s) {
	int len = strlen(s);
	Trie *cur = &root;
	for (int i=0;i<len;i++) {
		int v = s[i] - 'a';
		if (cur->ch[v] == NULL) return 0;
		cur = cur->ch[v];
	}
	return cur->cnt;
}
char tmp[15];
int main() {
	ncnt = 0;
	while (cin.getline(tmp,15)) {
		if (tmp[0] == '\0') break;
		insert(tmp);
	}
	while (scanf("%s",tmp) == 1) {
		printf("%d\n",query(tmp));
	}
	return 0;
}
