#include <bits/stdc++.h>
using namespace std;
char s[105];
int main() {
	int T;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++) {
		printf("Case #%d: ",cas);
		int d = 0;
		scanf("%s",s);
		for (int i=0;s[i];i++) {
			int di = s[i] - '0';
			while (di > d) {
				printf("(");
				d ++;
			}
			while (di < d) {
				printf(")");
				d --;
			}
			printf("%c",s[i]);
		}
		while (d --) printf(")");
		printf("\n");
	}
	return 0;
}
