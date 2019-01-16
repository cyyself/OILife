#include <bits/stdc++.h>
using namespace std;
char s1[50005];
char s2[50005];
int jump[50005];
void getnext() {
	memset(jump,-1,sizeof(jump));
	int k = -1;
	jump[0] = -1;
	for (int i=1;s1[i]!=0;i++) {
		while (k != -1 && s1[i] != s1[k+1]) k = jump[k];
		if (s1[i] == s1[k+1]) k++;
		jump[i] = k;
	}
}
int main() {
	while (scanf("%s%s",s1,s2) == 2) {
		getnext();
		int k = -1;
		for (int i=0;s2[i] != 0;i++) {
			while (k != -1 && s2[i] != s1[k+1]) k = jump[k];
			if (s2[i] == s1[k+1]) k ++;
		}
		if (k != -1) {
			s1[k+1] = 0;
			printf("%s %d\n",s1,k+1);
		}
		else printf("0\n");
	}
	return 0;
}
