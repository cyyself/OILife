#include <bits/stdc++.h>
using namespace std;
char t[500005];
int nxt[500005];
int cnt[2];
int all[2];
int suf[2];
void getnext() {
	int k = -1;
	nxt[0] = -1;
	for (int i=1;t[i];i++) {
		while (k != -1 && t[i] != t[k+1]) k = nxt[k];
		if (t[i] == t[k+1]) k ++;
		nxt[i] = k;
	}
}
int main() {
	scanf("%s",t);
	for (int i=0;t[i];i++) cnt[t[i]-'0'] ++;
	scanf("%s",t);
	int n = strlen(t);
	for (int i=0;t[i];i++) all[t[i]-'0'] ++;
	getnext();
	for (int i=nxt[n-1]+1;t[i];i++) suf[t[i]-'0'] ++;
	if (cnt[0] >= all[0] && cnt[1] >= all[1]) {
		printf("%s",t);
		cnt[0] -= all[0];
		cnt[1] -= all[1];
		while (cnt[0] >= suf[0] && cnt[1] >= suf[1]) {
			printf("%s",t+(nxt[n-1]+1));
			cnt[0] -= suf[0];
			cnt[1] -= suf[1];
		}
	}
	while (cnt[0]) {
		printf("0");
		cnt[0] --;
	}
	while (cnt[1]) {
		printf("1");
		cnt[1] --;
	}
	printf("\n");
	return 0;
}
