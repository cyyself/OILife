#include <bits/stdc++.h>
using namespace std;
int main() {
	char s[5];
	while (scanf("%s",s) == 1) {
		sort(s,s+3);
		for (int i=0;i<3;i++) {
			if (i != 0) printf(" ");
			printf("%c",s[i]);
		}
		printf("\n");
	}
	return 0;
}