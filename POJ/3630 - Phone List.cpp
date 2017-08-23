#include <cstdio>
#include <cstring>
int n;
int p = 0;
bool flag = true;
struct Trie {
	bool exist;
	bool cover;
	int child[10];
	inline void clear() {
		exist = false;
		cover = false;
		memset(child,-1,sizeof(child));
	}
}t[1<<16];
inline int newnode() {
	t[++p].clear();
	return p;
}
bool insert(char *s) {
	int cur = 0;
	int len = strlen(s);
	for (int i=0;i<len;i++) {
		if (t[cur].child[s[i]-'0'] == -1) t[cur].child[s[i]-'0'] = newnode();
		cur = t[cur].child[s[i]-'0'];
		if (t[cur].exist) return false;
		if (i == len - 1) {
			if (t[cur].cover) return false;
			t[cur].exist = true;
		}
		t[cur].cover = true;
	}
	return true;
}
char buf[15];
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		t[0].clear();
		p = 0;
		flag = true;
		for (int i=0;i<n;i++) {
			scanf("%s",buf);
			if (flag) if (!insert(buf)) flag = false;
		}
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}