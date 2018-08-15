#include <bits/stdc++.h>
using namespace std;
char t[200005];
char s[400005];
int p[400005];
int main() {
	while (scanf("%s",t) == 1) {
		int d = t[0] - 'a';
		scanf("%s",t);
		int len = strlen(t);
		s[0] = '$';
		s[1] = '#';
		int j = 2;
		for (int i=0;i<len;i++) {
			s[j++] = t[i];
			s[j++] = '#';
		}
		len = j;
		int pos = 0;
		int mx = 0;
		int anslen = 0;
		int anspos = 0;
		for (int i=1;i<len;i++) {
			if (i < mx) p[i] = min(p[2*pos-i],mx-i);
			else p[i] = 1;
			while (s[i+p[i]] == s[i-p[i]]) p[i] ++;
			if (i + p[i] > mx) {
				mx = i + p[i];
				pos = i;
			}
			if ( (p[i]-1) > anslen) {
				anslen = (p[i]-1);
				anspos = (i-1)/2 - anslen/2;
			}
		}
		if (anslen >= 2) {
			printf("%d %d\n",anspos,anspos+anslen-1);
			for (int i=anspos;i<anspos+anslen;i++) {
				printf("%c",'a'+((t[i]-'a')+26-d)%26);
			}
			printf("\n");
		}
		else printf("No solution!\n");
	}
	return 0;
}
