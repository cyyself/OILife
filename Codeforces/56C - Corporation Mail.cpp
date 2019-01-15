#include <bits/stdc++.h>
using namespace std;
string s[1000];
int top;
char buf[1005];
int main() {
	scanf("%s",buf);
	int len = strlen(buf);
	string curname = "";
	int ans = 0;
	for (int i=0;buf[i] != 0;i++) {
		if (buf[i] == ':') {
			for (int i=0;i<top;i++) if (s[i] == curname) ans ++;
			s[top++] = curname;
			curname = "";
		}
		else if (buf[i] == '.') {
			if (curname != "") {
				for (int i=0;i<top;i++) if (s[i] == curname) ans ++;
				s[top++] = curname;
			}
			top --;
			curname = "";
		}
		else if (buf[i] != ',') {
			curname += buf[i];
		}
	}
	printf("%d\n",ans);
	return 0;	
}
