#include <bits/stdc++.h>
using namespace std;
unsigned a[10000005];
unsigned x,y,z;
unsigned rng61() {
	unsigned t;
	x ^= x << 16;
	x ^= x >> 5;
	x ^= x << 1;
	t = x;
	x = y;
	y = z;
	z = t ^ x ^ y;
	return z;
}
struct DATA {
	int seq;
	int val;
	friend bool operator < (const DATA &a,const DATA &b) {
		return a.val > b.val;
	}
}b[100];
unsigned ans[100];
int n,m;
int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int cas = 1;
	while (cin >> n >> m >> x >> y >> z) {
		for (int i=0;i<n;i++) a[i] = rng61();
		for (int i=0;i<m;i++) {
			b[i].seq = i;
			cin >> b[i].val;
		}
		sort(b,b+m);
		int last = n;
		for (int i=0;i<m;i++) {
			if (i != 0 && b[i].val == last) {
				ans[b[i].seq] = a[b[i].val];
				continue;
			}
			nth_element(a,a+b[i].val,a+last);
			ans[b[i].seq] = a[b[i].val];
			last = b[i].val;
		}
		cout << "Case #" << cas ++ << ":";
		for (int i=0;i<m;i++) cout << " " << ans[i];
		cout << "\n";
	}
	return 0;	
}
