#include <bits/stdc++.h>
using namespace std;
int n,b;
int a[105];
bool check(int x) {
	int cntl = 0;
	int cntr = 0;
	for (int i=0;i<x;i++) if (a[i] & 1) cntl ++;
	for (int i=x;i<n;i++) if (a[i] & 1) cntr ++;
	if (cntl + cntl == x && cntr + cntr == n - x) return true;
	return false;
}
vector <int> c;
int main() {
	scanf("%d%d",&n,&b);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=2;i<n;i+=2) {
		if (abs(a[i]-a[i-1]) <= b) if (check(i)) c.push_back(abs(a[i]-a[i-1]));
	}
	sort(c.begin(),c.end());
	int ans = 0;
	for (vector<int>::iterator it=c.begin();it != c.end();it ++) {
		int v = *it;
		if (v <= b) {
			b -= v;
			ans ++;
		}
		else break;
	}
	printf("%d\n",ans);
	return 0;
}