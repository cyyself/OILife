#include <bits/stdc++.h>
using namespace std;
char s[105];
char ans[105];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n;
		scanf("%d",&n);
		int need = (n + 1) / 2;
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		scanf("%s",s);
		int cnt = 0;
		for (int i=0;i<n;i++) {
			ans[i] = '\0';
			if (s[i] == 'S') {
				if (a) {
					a --;
					ans[i] = 'R';
					cnt ++;
				}
			}
			else if (s[i] == 'R') {
				if (b) {
					b --;
					ans[i] = 'P';
					cnt ++;
				}
			}
			else if (s[i] == 'P') {
				if (c) {
					c --;
					cnt ++;
					ans[i] = 'S';
				}
			}
		}
		if (cnt >= need) {
			printf("YES\n");
			for (int i=0;i<n;i++) {
				if (ans[i] == '\0') {
					if (a) {
						a --;
						ans[i] = 'R';
					}
					else if (b) {
						b --;
						ans[i] = 'P';
					}
					else if (c) {
						c --;
						ans[i] = 'S';
					}
				}
				printf("%c",ans[i]);
			}
			printf("\n");
		}
		else printf("NO\n");
 
	}
	return 0;
}
