#include <bits/stdc++.h>
using namespace std;
char s[105];
int pre[105];
int n;
bool check(int sum,int lastpos) {
	while (lastpos != n) {
		int nextpos = upper_bound(pre+lastpos+1,pre+n+1,pre[lastpos] + sum) - pre - 1;
		if (nextpos == lastpos || pre[nextpos] != pre[lastpos] + sum) return false;
		lastpos = nextpos;
	}
	return true;
}
int main() {
	scanf("%d",&n);
	scanf("%s",s);
	for (int i=1;i<=n;i++) pre[i] = pre[i-1] + (s[i-1] - '0');
	for (int i=1;i<n;i++) {
		if (check(pre[i],i)) {
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}
