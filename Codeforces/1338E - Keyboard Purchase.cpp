#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
char s[100005];
int cnt[20][20];
int f[1<<20];
int n,m;
int dfs(int s) {
	if (f[s] != inf) return f[s];
	int add = 0;
	for (int i=0;i<m;i++) if ( (s >> i) & 1) 
		for (int j=0;j<m;j++) if ( ! ((s >> j) & 1) ) add += cnt[i][j];
	for (int i=0;i<m;i++) if ( (s >> i) & 1) f[s] = min(f[s],add+dfs(s^(1<<i)));
	return f[s];
}
int main() {
	memset(f,0x3f,sizeof(f));
	f[0] = 0;
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	for (int i=0;i+1<n;i++) {
		cnt[s[i]-'a'][s[i+1]-'a'] ++;
		cnt[s[i+1]-'a'][s[i]-'a'] ++;
	}
	printf("%d\n",dfs((1<<m)-1));
	return 0;
}
