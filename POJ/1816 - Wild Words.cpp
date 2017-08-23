#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct Trie{
	vector <int> p;
	Trie *c[28];//child{0-25:a-z,26:*,27:?}
	Trie(){
		memset(c,0,sizeof(c));
	}
}root;
bool ans[100005];
char buf[25];
const int ls[128] = {
	-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,26,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,27,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,-1,-1,-1,-1
};
void insert(char *s,int p) {
	int len = strlen(s);
	Trie *n = &root;
	for (int i=0;i<len;i++) {
		if (n->c[ls[s[i]]] == NULL) n->c[ls[s[i]]] = new Trie;
		n = n->c[ls[s[i]]];
		if (i == len - 1) n->p.push_back(p);
	}
}
void DFS(char *s,Trie *n,int len) {
	if (len == 0 && n->p.size() != 0) for (unsigned int i=0;i<n->p.size();i++) ans[n->p[i]] = true;
	if (n->c[ls['*']] != NULL) for (int i=0;i<=len;i++) DFS(s+i,n->c[ls['*']],len-i);
	if (len > 0) {
		if (n->c[ls['?']] != NULL) DFS(s+1,n->c[ls['?']],len-1);
		if (n->c[ls[s[0]]] != NULL) DFS(s+1,n->c[ls[s[0]]],len-1);
	}
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) {
		scanf("%s",buf);
		insert(buf,i);
	}
	for (int i=0;i<m;i++) {
		memset(ans,false,sizeof(ans));
		scanf("%s",buf);
		DFS(buf,&root,strlen(buf));
		bool flag = false;
		for (int j=0;j<n;j++) if (ans[j]) {
			printf("%d ",j);
			flag = true;
		}
		if (!flag) printf("Not match");
		printf("\n");
	}
	return 0;
}