#include <bits/stdc++.h>
using namespace std;
inline bool judge(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_';
}
int main() {
	int n;
	scanf("%d",&n);
	char s[55];
	cin.getline(s,55);//skip \n
	while (n--) {
		cin.getline(s,55);
		int len = strlen(s);
		bool ans = true;
		if ( (s[0] < 'a' || s[0] > 'z') && (s[0] < 'A' || s[0] > 'Z') && s[0] != '_') ans = false;
		for (int i=0;i<len && ans;i++) if (!judge(s[i])) ans = false;		
		if (ans) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}