#include <bits/stdc++.h>
using namespace std;
char s[1005];
int main() {
	int T;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++) {
		int x,y;
		scanf("%d%d%s",&x,&y,s+1);
		printf("Case #%d: ",cas);
		int ans = -1;
		for (int i=1;s[i];i++) {
			if (s[i] == 'N') {
				y ++;
			}
			else if (s[i] == 'S') {
				y --;
			}
			else if (s[i] == 'W') {
				x --;
			}
			else x ++;
			if (abs(x) + abs(y) <= i) {
				ans = i;
				break;
			}
		}
		if (ans == -1) printf("IMPOSSIBLE\n");
		else printf("%d\n",ans);
	}
	return 0;
}
