#include <bits/stdc++.h>
using namespace std;
bool exist[10];
char s[100005];
int main() {
	int n;
	scanf("%d",&n);
	scanf("%s",s);
	for (int i=0;s[i];i++) {
		if (s[i] == 'L') {
			for (int j=0;j<10;j++) {
				if (!exist[j]) {
					exist[j] = true;
					break;
				}
			}
		}
		else if (s[i] == 'R') {
			for (int j=9;j>=0;j--) {
				if (!exist[j]) {
					exist[j] = true;
					break;
				}
			}
		}
		else exist[s[i]-'0'] = false;
	}
	for (int i=0;i<10;i++) printf("%c",exist[i]?'1':'0');
	return 0;
}
