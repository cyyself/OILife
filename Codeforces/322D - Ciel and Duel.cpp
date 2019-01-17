#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int acnt;
int d[105];
int dcnt;
char s[10];
vector <int> c;
int work1() {//只打掉攻击牌的情况
	int ans = 0;
	int p1 = 0;
	int p2 = c.size()-1;
	while (p1 < acnt && p2 >= 0) {
		if (a[p1] <= c[p2]) {
			ans += c[p2] - a[p1];
		}
		else break;
		p1 ++;
		p2 --;
	}
	return ans;
}
int work2() {
	int ans = 0;
	for (int i=0;i<dcnt;i++) {
		auto it = upper_bound(c.begin(),c.end(),d[i]);
		if (it < c.begin() || it >= c.end()) return 0;
		c.erase(it);
	}
	int p1 = 0;
	for (int i=0;i<acnt;i++) {
		auto it = lower_bound(c.begin(),c.end(),a[i]);
		if (it < c.begin() || it >= c.end() || *it < a[i]) return ans;
		ans += *it - a[i];
		c.erase(it);
	}
	for (auto x:c) ans += x;
	return ans;
}
int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) {
		int x;
		scanf("%s%d",s,&x);
		if (s[0] == 'A') a[acnt++] = x;
		else d[dcnt++] = x;
	}
	sort(a,a+acnt);
	sort(d,d+dcnt);
	for (int i=0;i<m;i++) {
		int x;
		scanf("%d",&x);
		c.push_back(x);
	}
	sort(c.begin(),c.end());
	int ans = work1();
	ans = max(ans,work2());
	printf("%d\n",ans);
	return 0;
}
