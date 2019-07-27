#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
long long qpow(long long a,long long b) {
	long long ret = 1;
	while (b) {
		if (b & 1) {
			ret *= a;
			ret %= mod;
		}
		a *= a;
		a %= mod;
		b >>= 1;
	}
	return ret;
}

#define F0(i, a, n) for (ll i=(a);i<(n);++i)
#define FN(i,a,b) for(ll i=(a);i>=ll(b);--i)
#define SZ(x) ((ll)(x).size())
typedef vector<ll>VLL;
typedef pair<ll, ll> PLL;
namespace linear_seq
{
	const ll N = 10010;
	ll s_res[N], s_base[N], s_c[N], s_md[N];
	VLL s_md2;
	void mul(ll *a, ll *b, ll k)
	{
		F0(i, 0, k + k)s_c[i] = 0;
		F0(i, 0, k)if (a[i])
			F0(j, 0, k)
			s_c[i + j] = (s_c[i + j] + a[i] * b[j]) % mod;
		FN(i, k + k - 1, k)if (s_c[i])
			F0(j, 0, SZ(s_md2))
			s_c[i - k + s_md2[j]] = (s_c[i - k + s_md2[j]] - s_c[i] * s_md[s_md2[j]]) % mod;
		F0(i, 0, k)a[i] = s_c[i];
	}
	ll solve(ll n, const VLL& a,const VLL&b)
	{
		ll ans = 0, pnt = 0, k = SZ(a);
		assert(SZ(a) == SZ(b));
		F0(i, 0, k)s_md[k - 1 - i] = -a[i]; s_md[k] = 1;
		s_md2.clear(); F0(i, 0, k)if (s_md[i])s_md2.push_back(i);
		F0(i, 0, k)s_res[i] = s_base[i] = 0; s_res[0] = 1;
		while ((1ll << pnt) <= n)++pnt;
		FN(p, pnt, 0)
		{
			mul(s_res, s_res, k);
			if ((n >> p) & 1)
			{
				FN(i, k - 1, 0)s_res[i + 1] = s_res[i]; s_res[0] = 0;
				F0(j, 0, SZ(s_md2))s_res[s_md2[j]] = (s_res[s_md2[j]] - s_res[k] * s_md[s_md2[j]]) % mod;
			}
		}
		F0(i, 0, k)ans = (ans + s_res[i] * b[i]) % mod;
		if (ans < 0)ans += mod;
		return ans;
	}
	VLL BM(const VLL&s)
	{
		VLL B(1,1),C(1, 1);
		ll L = 0, m = 1, b = 1;
		F0(n, 0, SZ(s))
		{
			ll d = 0;
			F0(i, 0, L + 1)d = (d + (ll)C[i] * s[n - i]) % mod;
			if (d == 0)++m;
			else if (2 * L <= n)
			{
				VLL T = C;
				ll c = mod - d * qpow(b, mod - 2) % mod;
				while (SZ(C) < SZ(B) + m)C.push_back(0);
				F0(i, 0, SZ(B))C[i + m] = (C[i + m] + c * B[i]) % mod;
				L = n + 1 - L; B = T; b = d; m = 1;
			}
			else
			{
				ll c = mod - d * qpow(b, mod - 2) % mod;
				while (SZ(C) < SZ(B) + m)C.push_back(0);
				F0(i, 0, SZ(B))C[i + m] = (C[i + m] + c * B[i]) % mod;
				++m;
			}
		}
		return C;
	}
	ll gao(const VLL& a, ll n)
	{
		VLL c = BM(a);
		c.erase(c.begin());
		F0(i, 0, SZ(c)) c[i] = (mod - c[i]) % mod;
		return solve(n, c, VLL(a.begin(), a.begin() + SZ(c)));
	}
	VLL ori_a, tmp_c;
	void init(const VLL& a)
	{
		tmp_c = BM(a);
		tmp_c.erase(tmp_c.begin());
		F0(i, 0, SZ(tmp_c)) tmp_c[i] = (mod - tmp_c[i]) % mod;
		ori_a = a;
	}
	ll prin(ll n)
	{
		return solve(n, tmp_c, VLL(ori_a.begin(), ori_a.begin() + SZ(tmp_c)));
	}
};
long long gcd(long long a,long long b) {
	if (b == 0) return a;
	else return gcd(b,a%b);
}
void sim(long long &a,long long &b) {
	long long g = gcd(abs(a),abs(b));
	a /= g;
	b /= g;
}
inline long long inv(long long x) {
	return qpow(x,mod-2);
}
long long p[3001];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		long long k,n;
		scanf("%lld%lld",&k,&n);
		if (n == -1) {
			cout << (2 * qpow(k+1,mod-2) ) % mod << endl;
			continue;
		}
		p[0] = 1;
		long long pi = inv(k);
		int _n = min(n,3000LL);
		for (int i=1;i<=_n;i++) p[i] = 0;
		for (int i=0;i<_n;i++) {
			for (int j=1;j<=k;j++) {
				if (i + j > _n) continue;
				p[i+j] += (p[i] * pi) % mod;
				p[i+j] %= mod;
			}
		}
		if (n <= 3000) {
			cout << p[n] << endl;
		}
		else {
			vector <long long> ans;
			for (int i=0;i<=3000;i++) ans.push_back(p[i]);
			cout << linear_seq::gao(ans,n) << endl;
		}
	}
	return 0;
}