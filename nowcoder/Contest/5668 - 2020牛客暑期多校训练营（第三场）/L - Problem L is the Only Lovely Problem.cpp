#include <bits/stdc++.h>
using namespace std;
char s[15];
int main() {
	scanf("%s",s);
	int n = strlen(s);
	for (int i=0;i<n;i++) s[i] |= 32;
	if (s[0] == 'l' && s[1] == 'o' && s[2] == 'v' && s[3] == 'e' && s[4] == 'l' && s[5] == 'y') printf("lovely\n");
	else printf("ugly\n");
	return 0;
}
