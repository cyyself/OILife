#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int cnt = 0;
struct Trie{
	int ec;//exist count
	Trie *ch[128];
	Trie():ec(0) {
		memset(ch,0,sizeof(ch));
	}
}root;
string buf;
void insert(string s) {
	int len = s.length();
	Trie *n = &root;
	for (int i=0;i<len;i++) {
		if (n->ch[s[i]] == NULL) n->ch[s[i]] = new Trie;
		n = n->ch[s[i]];
		if (i == len - 1) n->ec ++;
	}
}
void DFS(Trie *n,string s) {
	if (n->ec > 0) {
		cout << s;
		printf(" %0.4lf\n",(double)n->ec*100/cnt);
	}
	for (int i=0;i<128;i++)
		if (n->ch[i] != NULL) 
			DFS(n->ch[i],s+char(i));
}
int main() {
	while(getline(cin,buf)) {
		if (buf == "") continue;
		insert(buf);
		cnt ++;
	}
	DFS(&root,"");
	return 0;
}