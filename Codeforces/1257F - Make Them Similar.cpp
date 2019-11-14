#include <bits/stdc++.h>
using namespace std;
map <vector<int>,int> mem;
const long long mo1 = 998244353;
const long long mo2 = 1e9+7;
int a[100];
int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	n = unique(a,a+n) - a;
	for (int x=0;x<(1<<15);x++) {//前15bit
		vector <int> tmp;
		for (int i=0;i<n;i++) {
			tmp.push_back(__builtin_popcount((a[i] ^ x) & ((1 << 15) - 1)));
		}
		mem[tmp] = x;
	}
	int ans = -1;
	for (int _x=0;_x<(1<<15);_x++) {//后15bit
		int x = _x << 15;
		vector <int> cnt;
		int mx = 0;
		for (int i=0;i<n;i++) {
			cnt.push_back(__builtin_popcount((a[i] ^ x) & (((1 << 15) - 1) << 15)));
			mx = max(mx,cnt[i]);
		}
		for (int all=mx;all<=30;all++) {
			vector <int> tmp;
			for (int i=0;i<n;i++) tmp.push_back(all-cnt[i]);
			if (mem.find(tmp) != mem.end()) ans = x | mem[tmp];
		}
	}
	printf("%d\n",ans);
	return 0;
}
