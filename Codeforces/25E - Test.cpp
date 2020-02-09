#include <bits/stdc++.h>
using namespace std;
const int maxl = 100005;
char s[3][maxl];
int nxt[3][maxl];
void getnext(char *P,int *jump) {
	jump[0] = -1;
	int k = -1;
	for (int i=1;P[i];i++) {
		while (k != -1 && P[i] != P[k+1]) k = jump[k];
		if (P[i] == P[k+1]) k ++;
		jump[i] = k;
	}
}
int sufmatch(char *T,char *P,int *jump,int m) {
	int k = -1;
	for (int i=0;T[i];i++) {
		while (k != -1 && T[i] != P[k+1]) k = jump[k];
		if (T[i] == P[k+1]) k++;
		if (k == m - 1) {
			return m - 1;
		}
	}
	return k;
}
char tmp[3*maxl];
int main() {
	scanf("%s%s%s",s[0],s[1],s[2]);
	int len[3] = {strlen(s[0]),strlen(s[1]),strlen(s[2])};
	getnext(s[0],nxt[0]);
	getnext(s[1],nxt[1]);
	getnext(s[2],nxt[2]);
	int p[3] = {0,1,2};
	int ans = len[0] + len[1] + len[2];
	do {
		memcpy(tmp,s[p[0]],len[p[0]]);
		tmp[len[p[0]]] = 0;
		int dec1 = sufmatch(tmp,s[p[1]],nxt[p[1]],len[p[1]]) + 1;
		int j = len[p[0]];
		for (int i=dec1;i<len[p[1]];i++) tmp[j++] = s[p[1]][i];
		tmp[j] = 0;
		int dec2 = sufmatch(tmp,s[p[2]],nxt[p[2]],len[p[2]]) + 1;
		ans = min(ans,j+len[p[2]]-dec2);
	}
	while (next_permutation(p,p+3));
	printf("%d\n",ans);
	return 0;
}
