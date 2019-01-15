#include <bits/stdc++.h>
using namespace std;
int main() {
	char s[15];
	scanf("%s",s);
	int len = strlen(s);
	bool flag = true;
	for (int i=0;i< len && flag;i++) {
		if (s[i] == '1' && s[i+1] == '4' && s[i+2] == '4') i += 2;
		else if (s[i] == '1' && s[i+1] == '4') i += 1;
		else if (s[i] != '1') {
			flag = false;
		}
	}
	if (flag) printf("YES\n");
	else printf("NO\n");
	return 0;
}
