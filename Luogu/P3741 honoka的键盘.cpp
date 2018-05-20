#include <bits/stdc++.h>
using namespace std;
int n;
char s[105];
int count() {
	int cnt = 0;
	for (int i=0;i<n;i++) {
		if (s[i] == 'V' && s[i+1] == 'K') cnt++;
	}
	return cnt;
}
int main() {
	scanf("%d",&n);
	scanf("%s",s);
	int ans = count();
	for (int i=0;i<n;i++) {
		if (s[i] == 'V') {
			s[i] = 'K';
			ans = max(ans,count());
			s[i] = 'V';
		}
		else {
			s[i] = 'V';
			ans = max(ans,count());
			s[i] = 'K';
		}
	}
	printf("%d\n",ans);
	return 0;
}
