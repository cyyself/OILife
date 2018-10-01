#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char f[1001][100];
void sum(char *a,char *b,char *dst) {
	int alen = strlen(a);
	int blen = strlen(b);
	char ret[100] = {0};
	int retlen = 0;
	int rem = 0;
	for (int i=0;i<max(alen,blen);i++) {
		int x = i<alen ? a[alen-i-1]-'0':0;
		int y = i<blen ? b[blen-i-1]-'0':0;
		int cur = x + y + rem;
		ret[retlen++] = (cur % 10) + '0';
		rem = cur / 10;
	}
	if (rem) {
		ret[retlen++] = rem + '0';
	}
	reverse(ret,ret+retlen);
	memcpy(dst,ret,retlen+1);
}
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	f[0][0] = '1';
	for (int i=1;i<=k;i++)
		for (int j=1;j<=n;j++) if (j-i >= 0) sum(f[j],f[j-i],f[j]);
	printf("%s\n",f[n]);
	return 0;
}
