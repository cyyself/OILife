#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
char s[1000005];
int len;
int nxt[1000005];
void getnext() {
	int k = -1;
	nxt[0] = -1;
	for (int i=1;i<len;i++) {
		while (k != -1 && s[i] != s[k+1]) k = nxt[k];
		if (s[i] == s[k+1]) k ++;
		nxt[i] = k;
	}
}
int main() {
	while (true) {
		scanf("%s",s);
		if (s[0] == '.') break;
		len = strlen(s);
		getnext();
		int ans = 1;
		if (len % (len-(nxt[len-1]+1)) == 0) ans = len / (len-(nxt[len-1]+1));
		printf("%d\n",ans);
	}
	return 0;
}
