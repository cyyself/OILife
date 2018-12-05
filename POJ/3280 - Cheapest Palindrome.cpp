#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[2005];
int cost[26];
int f[2005][2005];
int main() {
	int n,m;
	scanf("%d%d%s",&n,&m,s);
	memset(cost,0x3f,sizeof(cost));
	for (int i=0;i<n;i++) {
		char c;
		int a,b;
		scanf(" %c%d%d",&c,&a,&b);
		cost[c-'a'] = min(a,b);
	}
	for (int len=2;len<=m;len++) {
		for (int i=0;i+len-1<m;i++) {
			int j = i + len - 1;
			f[i][j] = 0x3f3f3f3f;
			if (s[i] == s[j]) f[i][j] = min(f[i][j],f[i+1][j-1]);
			else {
				f[i][j] = min(f[i][j],f[i+1][j]+cost[s[i]-'a']);
				f[i][j] = min(f[i][j],f[i][j-1]+cost[s[j]-'a']);
			}
		}
	}
	printf("%d\n",f[0][m-1]);
	return 0;
}
