#include <bits/stdc++.h>
using namespace std;
char s1[1005];
char s2[1005];
int nxt[1005];
int len;
void getnext() {
	nxt[1] = 0;
	int k = 0;
	for (int i=2;i<=len;i++) {
		while (k != 0 && s2[k+1] != s2[i]) k = nxt[k];
		if (s2[k+1] == s2[i]) k++;
		nxt[i] = k;
	}
}
int main() {
	while (true) {
		scanf("%s",&s1[1]);
		if (s1[1] == '#') break;
		scanf("%s",&s2[1]);
		len = strlen(&s2[1]);
		getnext();
		int lena = strlen(&s1[1]);
		int k = 0;
		int ans = 0;
		for (int i=1;i<=lena;i++) {
			while (k != 0 && s2[k+1] != s1[i]) k = nxt[k];
			if (s2[k+1] == s1[i]) k++;
			if (k == len) {
				ans ++;
				k = 0;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
