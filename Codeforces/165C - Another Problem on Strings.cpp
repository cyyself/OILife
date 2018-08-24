#include <bits/stdc++.h>
using namespace std;
int pre[1000005];
int suf[1000005];
char s[1000005];
vector <int> zero;
vector <int> one;
long long gausssum(long long x) {
	return ((x+1)*x)/2;
}
int main() {
	int k;
	scanf("%d",&k);
	scanf("%s",s);
	int len = strlen(s);
	long long ans = 0;
	if (k == 0) {
		int cnt = 0;
		for (int i=0;i<len;i++) {
			if (s[i] == '0') cnt ++;
			else {
				ans += gausssum(cnt);
				cnt = 0;
			}
		}
		ans += gausssum(cnt);
	}
	else {
		for (int i=0;i<len;i++) if (s[i] == '1') one.push_back(i);
		for (int i=0;i+(k-1)<one.size();i++) {
			long long pre = one[i] - (i==0?-1:one[i-1]);
			long long suf = (i+k<one.size()?one[i+k]:len) - one[i+k-1];
			ans += pre * suf;
		}
	}
	cout << ans << endl;
	return 0;
}
