#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int l[200005],r[200005];
int a[200005];
int res[200005];
int e[200005];//这个节点要新开始覆盖的值
int main() {
	memset(l,0x3f,sizeof(l));
	memset(r,-1,sizeof(r));
	int n,q;
	scanf("%d%d",&n,&q);
	bool exist_q = false;//是否存在q
	for (int i=0;i<n;i++) {
		scanf("%d",&a[i]);
		l[a[i]] = min(i,l[a[i]]);
		r[a[i]] = max(i,r[a[i]]);
	}
	for (int qi=2;qi<=q;qi++) {
		if (l[qi] != INF) e[l[qi]] = qi;//记录每个query的起始位置
	}
	//开始覆盖
	stack <int> st;
	for (int i=0;i<n;i++) res[i] = 1;
	for (int i=0;i<n;i++) {
		if (e[i]) {
			if (st.empty() || (!st.empty() && e[i] > st.top()) ) st.push(e[i]);//要考虑这个区间内覆盖了更小的数的情况
		}
		if (!st.empty()) res[i] = st.top();
		if (!st.empty()) if (r[st.top()] == i) st.pop();
	}
	//判断是否有a[i] != 0且与覆盖结果不符的
	bool ans = true;
	for (int i=0;i<n;i++) {
		if (a[i] != 0 && res[i] != a[i]) {
			ans = false;
			break;
		}
	}
	//因为q是最后一次覆盖，所以q一定存在的，找到一个0的位置把它填上，如果不存在0的位置显然是不可能的
	if (l[q] == INF) {
		bool exist = false;
		for (int i=0;i<n && !exist;i++) if (a[i] == 0) {
			exist = true;
			res[i] = q;
		}
		if (!exist) ans = false;
	}
	if (ans) {
		printf("YES\n");
		for (int i=0;i<n;i++) {
			if (i != 0) printf(" ");
			printf("%d",res[i]);
		}
		printf("\n");
	}
	else printf("NO\n");
	return 0;
}
