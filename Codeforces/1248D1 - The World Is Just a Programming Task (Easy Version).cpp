#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
char s[maxn];
int n;
int cal() {
	pair <int,int> pre[505],suf[505];
	memset(pre,0,sizeof(pre));
	memset(suf,0,sizeof(suf));
	for (int i=1;i<=n;i++) {
		pre[i] = pre[i-1];
		if (s[i] == '(') {
			pre[i].first ++;
		}
		else {
			if (pre[i].first > 0) pre[i].first --;
			else pre[i].second ++;
		}
	}
	for (int i=n;i>=1;i--) {
		suf[i] = suf[i+1];
		if (s[i] == ')') {
			suf[i].second ++;
		}
		else {
			if (suf[i].second > 0) suf[i].second --;
			else suf[i].first ++;
		}
	}
	int ret = 0;
	for (int i=0;i<n;i++) {
		if (pre[i].second == suf[i+1].first && pre[i].first == 0 && suf[i+1].second == 0) {
			ret ++;
		}
	}
	return ret;
}
int main() {
	scanf("%d",&n);
	scanf("%s",s+1);
	int ans = -1,ansl,ansr;
	for (int l=1;l<=n;l++) for (int r=1;r<=n;r++) {
		swap(s[l],s[r]);
		int tmp = cal();
		if (tmp > ans) {
			ans = tmp;
			ansl = l;
			ansr = r;
		}
		swap(s[l],s[r]);
	}
	printf("%d\n%d %d\n",ans,ansl,ansr);
	return 0;
}
