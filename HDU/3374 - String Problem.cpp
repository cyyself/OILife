#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int len;
int strmin(char *s) {
	int i=0,j=1,k=0;
	while (i < len && j < len && k < len) {
		int d = s[(i+k)%len] - s[(j+k)%len];
		if (d == 0) k ++;
		else {
			if (d > 0) i = i + k + 1;
			else j = j + k + 1;
			if (i == j) j ++;
			k = 0;
		}
	}
	return min(i,j);
}
int strmax(char *s) {
	int i=0,j=1,k=0;
	while (i < len && j < len && k < len) {
		int d = s[(i+k)%len] - s[(j+k)%len];
		if (d == 0) k ++;
		else {
			if (d < 0) i = i + k + 1;
			else j = j + k + 1;
			if (i == j) j ++;
			k = 0;
		}
	}
	return min(i,j);
}
int nxt[1000005];
int getnext(int p) {
	int k = -1;
	nxt[0] = -1;
	for (int i=1;i<len;i++) {
		while (k != -1 && s[(i+p)%len] != s[(k+1+p)%len]) k = nxt[k];
		if (s[(i+p)%len] == s[(k+1+p)%len]) k ++;
		nxt[i] = k;
	}
	return k;
}
int main() {
	while (scanf("%s",s) == 1) {
		len = strlen(s);
		int r1 = strmin(s);
		int t1 = getnext(r1) + 1;
		int r2 = strmax(s);
		int t2 = getnext(r2) + 1;
		printf("%d %d %d %d\n",r1+1,len%(len-t1)==0?len/(len-t1):1,r2+1,len%(len-t2)==0?len/(len-t2):1);
	}
	return 0;
}
