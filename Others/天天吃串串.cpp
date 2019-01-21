#include <bits/stdc++.h>
using namespace std;
char a[200005];
char b[400005];
int  p[400005];
int  r[400005];//这个位置可以覆盖到的区间
int main() {
	while (scanf("%s",a) == 1) {
		int lena = strlen(a);
		b[0] = '$';
		b[1] = '#';
		int j = 2;
		for (int i=0;i<lena;i++) {
			b[j++] = a[i];
			b[j++] = '#';
		}
		b[j] = '\0';
		int lenb = strlen(b);
		int id = 0;
		int mx = 0;
		for (int i=1;i < lenb;i++) {
			if (i < mx) p[i] = min(p[2*id-i],mx - i);
			else p[i] = 1;
			while (b[i-p[i]] == b[i+p[i]]) p[i] ++;
			if (mx < i + p[i]) {
				id = i;
				mx = i + p[i];
			}
			r[i-p[i]+1] = i + p[i] - 1;
		}
		int ans  = 0;
		int nxt  = r[1] + 2;
		int maxr = r[1] + 2;
		for (int i=1;i<lenb;i++) {
			if (i == nxt) {
				ans ++;
				nxt = maxr;
			}
			maxr = max(maxr,r[i]+2);
		}
		printf("%d\n",ans);
	}
	return 0;
}
