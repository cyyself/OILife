#include <cstdio>
#include <cstring>
struct Trie{
	bool exist;
	Trie *child[2];
	Trie():exist(false){
		memset(child,false,sizeof(child));
	}
}root;
char buf[25];
bool flag = true;
void del(Trie *n) {
	for (int i=0;i<2;i++) if(n->child[i] != NULL) del(n->child[i]);
	delete n;
}
void clearnode(Trie *n) {
	n->exist = false;
	for (int i=0;i<2;i++) {
		if (n->child[i] != NULL) {
			del(n->child[i]);
			n->child[i] = NULL;
		}
	}
}
bool insert(char *s) {
	Trie *n = &root;
	int len = strlen(s);
	for (int i=0;i<len;i++) {
		if (n->child[s[i]-'0'] == NULL) n->child[s[i]-'0'] = new Trie;
		n = n->child[s[i]-'0'];
		if (n->exist) return false;
		if (i == len - 1) n->exist = true;
	}
	return true;
}
int main() {
	int T = 0;
	while(scanf(" %s",buf) == 1) {
		if (buf[0] == '9') {
			if (flag) printf("Set %d is immediately decodable\n",++T);
			else printf("Set %d is not immediately decodable\n",++T);
			flag = true;
			clearnode(&root);
		}
		else {
			if(flag) if(!insert(buf)) flag = false;;
		}
	}
	return 0;
}