//https://pintia.cn/problem-sets/994805046380707840/problems/994805065406070784
#include <bits/stdc++.h>
using namespace std;
int p[31];
int m[31];
map <int,int> pos;//中序遍历中元素的位置
vector <int> ans[35];
void build_tree(int dep,int lp,int rp,int lm,int rm) {
	int rootv = p[lp];
	ans[dep].push_back(rootv);
	int lenl = pos[rootv] - lm;
	int lenr = rm - pos[rootv];
	if (lenl > 0) {
		build_tree(dep+1,lp+1,lp+lenl,lm,lm+lenl-1);
	}
	if (lenr > 0) {
		build_tree(dep+1,rp-lenr+1,rp,rm-lenr+1,rm);
	}
}
int main() {
	int n;
	scanf("%d",&n);
	if (n == 0) return 0;
	for (int i=0;i<n;i++) {
		scanf("%d",&m[i]);
		pos[m[i]] = i;
	}
	for (int i=0;i<n;i++) {
		scanf("%d",&p[i]);
	}
	build_tree(0,0,n-1,0,n-1);
	for (int i=0;i<35;i++) reverse(ans[i].begin(),ans[i].end());
	printf("%d",ans[0][0]);
	int cur = 1;
	while (ans[cur].size() > 0) {
		for (auto x:ans[cur]) printf(" %d",x);
		cur ++;
	}
	printf("\n");
	return 0;
}
