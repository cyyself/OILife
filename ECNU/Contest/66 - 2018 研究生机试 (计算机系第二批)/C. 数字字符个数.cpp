#include <bits/stdc++.h>
using namespace std;
char s[105];
int main() {
	cin.getline(s,105);
	int len = strlen(s);
	int ans = 0;
	for (int i=0;i<len;i++) if (s[i] >= '0' && s[i] <= '9') ans ++;
	printf("%d\n",ans);
	return 0;
}