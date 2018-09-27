#include <bits/stdc++.h>
using namespace std;
char s[55];
int nxt[55];
int n;
void getnext() {
	nxt[0] = -1;
	int k = -1;
	for (int i=1;i<n;i++) {
		while (k != -1 && s[i] != s[k+1]) k = nxt[k];
		if (s[i] == s[k+1]) k++;
		nxt[i] = k;
	}
}
int main() {
	int k;
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	getnext();
	for (int i=0;i<n;i++) printf("%c",s[i]);
	for (int j=1;j<k;j++) for (int p=nxt[n-1]+1;p<n;p++) printf("%c",s[p]);
	printf("\n");
	return 0;
}
