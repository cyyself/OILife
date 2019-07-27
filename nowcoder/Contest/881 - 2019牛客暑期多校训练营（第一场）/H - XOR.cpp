#include <bits/stdc++.h>
using namespace std;
const long long mo = 1e9+7;
struct LB {
	long long r[63];
	LB() {
		memset(r,0,sizeof(r));
	}
	LB(const LB &b) {
		for (int i=0;i<63;i++) r[i] = b.r[i];
	}
	bool insert(long long x) {
		for (int i=62;i>=0;i--) {
			if ((x >> i) & 1) {
				if (r[i] == 0) {
					r[i] = x;
					return true;
				}
				else x ^= r[i];
			}
		}
		return false;
	}
	bool check(long long x) {
		for (int i=62;i>=0;i--) {
			if ((x >> i) & 1) {
				if (r[i] == 0) return false;
				x ^= r[i];
			}
		}
		return true;
	}
};
long long qpow(long long a,long long b) {
	long long ret = 1;
	while (b) {
		if (b & 1) {
			ret *= a;
			ret %= mo;
		}
		a *= a;
		a %= mo;
		b >>= 1;
	}
	return ret;
}
long long a[100005];
vector <long long> inA;
vector <long long> ninA;
int main() {
	int n;
	while (scanf("%d",&n) == 1) {
		inA.clear();
		ninA.clear();
		for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
		LB A;
		for (int i=1;i<=n;i++) {
			if (A.insert(a[i])) inA.push_back(a[i]);
			else ninA.push_back(a[i]);
		}
		if (inA.size() == n) {
			printf("0\n");
		}
		else {
			long long ans = (1LL * ninA.size() * qpow(2,1LL*ninA.size()-1LL)) % mo;
			LB B;
			int Bcnt = 0;
			for (auto x:ninA) Bcnt += B.insert(x);
			for (int i=0;i<inA.size();i++) {
				LB t(B);
				int cnt = Bcnt;
				for (int j=0;j<inA.size();j++) {
					if (j == i) continue;
					cnt += t.insert(inA[j]);
				}
				if (t.check(inA[i])) {
					ans += qpow(2,n-cnt-1);
					ans %= mo;
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}