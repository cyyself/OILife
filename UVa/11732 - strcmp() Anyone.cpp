#include <cstdio>
#include <cstring>
struct Trie {
	int cnt;
	char c;
	Trie *son,*bro;
	Trie():cnt(0),c(-1),son(NULL),bro(NULL){}
}root;
long long ans = 0;
char buf[1005];
inline Trie* GotoBrother(Trie *n,char c){
	//找到字符为c的兄弟，找到了最后一个兄弟节点还没找到则创建之
	//我一直觉得左儿子右兄弟还不如写邻接表（逃
	Trie *cur = n;
	while(cur->c != c) {
		if (cur->bro == NULL) {
			cur->bro = new Trie;
			cur = cur->bro;
			cur->c = c;
		}
		else cur = cur->bro;
	}
	return cur;
}
void insert(char *s,int l) {//l:已经在树中的字符串数量
	Trie *cur = &root;
	int len = strlen(s);
	for (int i=0;i<=len;i++) {
		if (cur->son == NULL) cur->son = new Trie;
		cur=cur->son;
		cur=GotoBrother(cur,s[i]);
		ans += (l - cur->cnt)*(2*i + 1);
		//printf("debug:l=%d,cur->cnt=%d,ans=%lld\n",l,cur->cnt,ans);
		if (len == i) ans += cur->cnt*(2*i + 2);
		/*
		没加这上面这行过了样例愉快地交题然后WA了一小时纪念
		感谢udebug第三个数据点
		感谢http://blog.csdn.net/hcbbt/article/details/39523729#
		注意当比到\0时相同字符串的比较问题。
		举个例子
		输入数据：
		2
		ab
		ab
		0
		输出数据：
		6
		错误输出：
		0
		这时比到了\0位置，也就是i=2=len的位置
		因为路径上一直都有同样的字符串，l - cur->cnt始终等于0
		但是实际上比较了(2*i+1)*cur->cnt次
		因此，对于这种最后比较时已经被前面的字符串覆盖过的情况，还要把ans加上最后一个节点的cnt*(2*i + 2)
		*/
		l = cur->cnt;
		cur->cnt ++;
	}
}
void del(Trie *n) {
	if (n->son != NULL) del(n->son);
	if (n->bro != NULL) del(n->bro);
	delete n;
}
int main() {
	int n;
	int T = 0;
	while (scanf("%d",&n) == 1) {
		if (n == 0) break;
		T++;
		ans = 0;
		root.cnt = 0;
		if (root.son != NULL) del(root.son);
		root.son = NULL;
		for (int i=0;i<n;i++) {
			scanf("%s",buf);
			insert(buf,i);
		}
		printf("Case %d: %lld\n",T,ans);
	}
	return 0;
}
