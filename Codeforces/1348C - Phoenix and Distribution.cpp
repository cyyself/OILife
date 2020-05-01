#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
char s[maxn];
int cnt[26];
vector <char> buf[maxn];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n,k;
		scanf("%d%d",&n,&k);
		scanf("%s",s);
		sort(s,s+n);
		if (k == n) {
			printf("%c\n",s[n-1]);
		}
		else if (k == 1) {
			printf("%s\n",s);
		}
		else {
			if (s[0] == s[k-1]) {
				if (s[k] == s[n-1]) {
					//后面都相等，均分
					int len = (n-1-k+1 + (k-1)) /k;
					printf("%c",s[0]);
					for (int i=0;i<len;i++) printf("%c",s[k]);
					printf("\n"); 
				}
				else {
					//不相等，分一个
					printf("%c%s\n",s[0],&s[k]);
				}
			}
			else printf("%c\n",s[k-1]);
		}
	}
	return 0;
}
