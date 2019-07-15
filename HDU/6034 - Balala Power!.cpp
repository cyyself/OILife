#include <bits/stdc++.h>
using namespace std;
long long a[26][110000];
const int mo = 1000000007;
struct DATA {
	bool flag;
	int sz;
	long long *x;
	void sim() {
		int i = 0;
		while (i < sz) {
			if (x[i] >= 26) {
				while (i + 1 >= sz) x[sz++] = 0;
				x[i+1] += x[i] / 26;
				x[i] %= 26;
			}
			i ++;
		}
	}
	friend bool operator < (const DATA &a,const DATA &b) {
		if (a.sz != b.sz) return a.sz < b.sz;
		for (int i=a.sz-1;i>=0;i--) if (a.x[i] != b.x[i]) return a.x[i] < b.x[i];
		return false;
	}
}d[26];
char s[100005];
long long w[110000];
int main() {
	w[0] = 1;
	for (int i=1;i<110000;i++) {
		w[i] = w[i-1] * 26;
		w[i] %= mo;
	}
	int n;
	int cas = 1;
	while (scanf("%d",&n) == 1) {
		for (int i=0;i<26;i++) {
			d[i].sz = 0;
			d[i].flag = false;
			d[i].x = a[i];
		}
		for (int j=0;j<n;j++) {
			scanf("%s",s);
			int len = strlen(s);
			d[s[0]-'a'].flag = true;
			for (int i=0;i<len;i++) {
				while (len-1-i >= d[s[i]-'a'].sz) d[s[i]-'a'].x[d[s[i]-'a'].sz++] = 0;
				d[s[i]-'a'].x[len-1-i] ++;
			}
		}
		for (int i=0;i<26;i++) d[i].sim();
		sort(d,d+26);
		int ptr = 0;
		while (d[ptr].flag) ptr ++;
		while (ptr) {
			swap(d[ptr],d[ptr-1]);
			ptr --;
		}
		long long ans = 0;
		for (int i=0;i<26;i++) for (int j=0;j<d[i].sz;j++) {
			ans += i * d[i].x[j] * w[j];
			ans %= mo;
		}
		printf("Case #%d: %lld\n",cas++,ans);
	}
	return 0;
}
