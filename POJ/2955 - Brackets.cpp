#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[105];
int f[105][105];
bool judge(char a,char b) {
	if (a == '(' && b == ')') return true;
	if (a == '[' && b == ']') return true;
	return false;
}
int main() {
	while (scanf("%s",s) == 1 && s[0] != 'e') {
		memset(f,0,sizeof(f));
		int n = strlen(s);
		for (int i=1;i<n;i++) {
			f[i-1][i] = 2 * judge(s[i-1],s[i]);
		}
		for (int len=3;len<=n;len ++) {
			for (int i=0;i+len-1<n;i++) {
				int j = i + len - 1;
				if (judge(s[i],s[j])) f[i][j] = max(f[i][j],f[i+1][j-1] + 2);
				for (int mid=i;mid<j;mid++) {
					f[i][j] = max(f[i][j],f[i][mid]+f[mid+1][j]);
				}
			}
		}
		printf("%d\n",f[0][n-1]);
	}
	return 0;
}
