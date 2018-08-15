#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char t[1000005];
char s[2000005];
int p[2000005];
int main() {
	int c = 1;
	while (scanf("%s",t) == 1) {
		int len = strlen(t);
		if (len == 3) {
			if (t[0] == 'E' && t[1] == 'N' && t[2] == 'D') break;
		}
		s[0] = '$';
		s[1] = '#';
		int j = 2;
		for (int i=0;i<len;i++) {
			s[j++] = t[i];
			s[j++] = '#';
		}
		len = j;
		int mx = 0;
		int pos = 0;
		int ans = 0;
		for (int i=1;i<len;i++) {
			if (i < mx) p[i] = min(p[2*pos-i],mx-i);
			else p[i] = 1;
			while (s[i+p[i]] == s[i-p[i]] ) p[i] ++;
			if (i + p[i] > mx) {
				mx = i + p[i];
				pos = i;
			}
			ans = max(ans,p[i]-1);
		}
		printf("Case %d: %d\n",c++,ans);
	}
	return 0;
}
