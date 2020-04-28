#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
char s[maxn];
int cnt[10],sel[10];
bool ok;
int k;
void dfs(int dep,int cur,int exist) {
	if (dep == -1) {
		if (cur == 0 && exist == k) {
			for (int i=9;i>=0;i--) {
				for (int j=0;j<sel[i];j++) printf("%d",i);
			}
			printf("\n");
			ok = true;
		}
	}
	else {
		int avail = min(cnt[dep],k-exist);
		if (dep == 0 && exist == 0 && k != 1) return;//不能含前导0
		for (int i=avail;i>=max(0,avail-2) && !ok;i--) {
			sel[dep] = i;
			dfs(dep-1,(cur+dep*i)%3,exist+i);
		}
	}
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		scanf("%s%d",s,&k);
		int n = strlen(s);
		memset(cnt,0,sizeof(cnt));
		for (int i=0;i<n;i++) cnt[s[i]-'0'] ++;
		ok = false;
		dfs(9,0,0);
		if (!ok) printf("-1\n");
	}
	return 0;
}
