#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
char s[105][105];
int bs[62];
char gench(int x) {
	if (x <= 9) return '0' + x;
	else if (x <= 35) return 'a' + x - 10;
	else return 'A' + x - 36;
}
char ans[105][105];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int r,c,k;
		scanf("%d%d%d",&r,&c,&k);
		for (int i=0;i<r;i++) scanf("%s",s[i]);
		int cnt = 0;
		for (int i=0;i<r;i++) {
			for (int j=(i&1?c-1:0);(i&1?j>=0:j<c);(i&1?j--:j++)) {
				if (s[i][j] == 'R') cnt ++;
			}
		}
		for (int i=0;i<k;i++) bs[i] = cnt / k;
		int rem = cnt % k;
		for (int i=0;i<rem;i++) bs[i] ++;
		int ptr = 0, cur = 0;
		for (int i=0;i<r;i++) {
			for (int j=(i&1?c-1:0);(i&1?j>=0:j<c);(i&1?j--:j++)) {
				if (ptr == k) ans[i][j] = gench(ptr - 1);
				else {
					if (s[i][j] == 'R') cur ++;
					ans[i][j] = gench(ptr);
					if (cur == bs[ptr]) {
						cur = 0;
						ptr ++;
					}
				}
			}
			ans[i][c] = '\0';
		}
		assert(ptr == k && cur == 0);
		for (int i=0;i<r;i++) {
			printf("%s\n",ans[i]);
		}
	}
	return 0;
}
