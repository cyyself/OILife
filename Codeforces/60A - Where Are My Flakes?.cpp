#include <bits/stdc++.h>
using namespace std;
char s[4][15];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	int l = 1;
	int r = n;
	while (m --) {
		int x;
		scanf("%s%s%s%s%d",&s[0][0],&s[1][0],&s[2][0],&s[3][0],&x);
		if (s[2][0] == 'l') {
			r = min(r,x-1);
		}
		else {
			l = max(l,x+1);
		}
	}
	if (l <= r) printf("%d\n",r-l+1);
	else printf("-1\n");
	return 0;
}
