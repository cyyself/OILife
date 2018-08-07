#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int nxt[1000005];
int len;
void getnext() {
	int k = -1;
	nxt[0] = -1;
	for (int i=1;i<len;i++) {
		while (k != -1 && s[i] != s[k+1]) k = nxt[k];
		if (s[i] == s[k+1]) k++;
		nxt[i] = k;
		if (i >= 1 && k >= 0) {
			if ((i+1) % (i-nxt[i]) == 0) printf("%d %d\n",(i+1),(i+1)/(i-nxt[i]));
		}
	}
}
int main() {
	int n;
	int c = 1;
	while (scanf("%d",&n) == 1) {
		if (n == 0) break;
		scanf("%s",s);
		len = strlen(s);
		printf("Test case #%d\n",c++);
		getnext();
		printf("\n");
	}
	return 0;
}
