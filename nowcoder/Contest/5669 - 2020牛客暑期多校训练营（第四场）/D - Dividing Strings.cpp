#include <bits/stdc++.h>
using namespace std;
const long long mo = 998244353;
const int maxn = 1e5+5;
long long suf[maxn];
char s[maxn];
long long ten[maxn],inv_ten[maxn];
int suf9[maxn],suf0[maxn];
long long qpow(long long a,long long b) {
	long long res = 1;
	while (b) {
		if (b & 1) {
			res *= a;
			res %= mo;
		}
		b >>= 1;
		a *= a;
		a %= mo;
	}
	return res;
}
int n;
long long gethash(int l,int r) {
	long long x = (suf[l] - suf[r+1] + mo) % mo;
	int len = n - r;
	x = (x * inv_ten[len]) % mo;
	return x;
}
void init() {
	ten[0] = 1;
	for (int i=1;i<=1e5;i++) ten[i] = (ten[i-1] * 10) % mo;
	inv_ten[100000] = qpow(ten[100000],mo-2);
	for (int i=1e5-1;i>=0;i--) inv_ten[i] = (inv_ten[i+1] * 10) % mo;
	assert(inv_ten[0] == 1);
}
int main() {
	init();
	int T;
	scanf("%d",&T);
	while (T --) {
		scanf("%d",&n);
		scanf("%s",s+1);
		int MI = 9, MA = 0;
		suf[n+1] = 0;
		suf9[n+1] = 0;
		suf0[n+1] = 0;
		for (int i=n;i>=1;i--) {
			MI = min(MI,s[i] - '0');
			MA = max(MA,s[i] - '0');
			suf[i] = (suf[i+1] + (s[i] - '0') * ten[n-i]) % mo;
			if (s[i] == '9') {
				suf9[i] = suf9[i+1] + 1;
			}
			else suf9[i] = 0;
			if (s[i] == '0') {
				suf0[i] = suf0[i+1] + 1;
			}
			else suf0[i] = 0;
		}
		int ans = MA - MI;
		if (ans == 0) printf("0\n");
		else {
			if (n > 2) {
				int mi_2 = 0x3f3f3f3f;
				int ma_2 = 0;
				for (int i=1;i<=n;i++) {
					int cur = s[i] - '0';
					if (cur == 1) {
						if (i + 1 <= n) {
							int nxt = s[i+1] - '0';
							mi_2 = min(mi_2,10+nxt);
							ma_2 = max(ma_2,10+nxt);
							i ++;
						}
						else {
							mi_2 = min(mi_2,1);
							ma_2 = max(ma_2,1);
						}
					}
					else {
						mi_2 = min(mi_2,cur);
						ma_2 = max(ma_2,cur);
					}
				}
				ans = min(ans,ma_2-mi_2);
			}
			for (int len=2;len<=(n+1)/2;len++) {//单个长度
				if (s[1] == '1' && suf0[2] >= len - 2) {
					//开头是10000.....
					int hi = len;
					int lo = len - 1;
					long long mi = 0, ma = 0;
					long long prefi = gethash(1,len-1);
					long long lastfi = s[len] - '0';
					int ptr = len+1;
					bool ok = true;
					while (ptr <= n && ma - mi < ans) {
						if (n - ptr + 1 >= lo) {
							if (s[ptr] == '9') {//lo
								long long lastx = s[ptr+lo-1] - '0';
								if (suf9[ptr] >= lo - 1) {
									long long d = -lastfi - (10 - lastx);
									mi = min(mi,d);
									ma = max(ma,d);
								}
								else {
									ok = false;
									break;
								}
								ptr += lo;
							}
							else {//hi
								if (n - ptr + 1 < hi) {
									ok = false;
									break;
								}
								long long lastx = s[ptr+hi-1] - '0';
								long long prex = gethash(ptr,ptr+hi-2);
								if (prex == prefi) {
									long long d = lastx - lastfi;
									mi = min(mi,d);
									ma = max(ma,d);
								}
								else if ((prefi + 1) % mo == prex) {
									long long d = (10 - lastfi) + lastx;
									mi = min(mi,d);
									ma = max(ma,d);
								}
								else {
									ok = false;
									break;
								}
								ptr += hi;
							}
						}
						else {
							ok = false;
							break;
						}
					}
					if (ok && ptr == n + 1) ans = min(1ll*ans,1ll*ma-mi);
				}
				else if (suf9[1] >= len - 1) {
					//开头是99999......
					int lo = len;
					int hi = len + 1;
					long long mi = 0,ma = 0;
					long long prefi = gethash(1,len-1);
					long long lastfi = s[len] - '0';
					int ptr = len + 1;
					bool ok = true;
					while (ptr <= n && ma - mi < ans) {
						if (n - ptr + 1 >= lo) {
							if (s[ptr] == '9' || s[ptr] == '8') {//lo
								long long prex = gethash(ptr,ptr+lo-2);
								long long lastx = s[ptr+lo - 1] - '0';
								if (prex == prefi) {
									long long d = lastx - lastfi;
									mi = min(mi,d);
									ma = max(ma,d);
								}
								else if ((prex + 1) % mo == prefi) {
									long long d = -(10 - lastx) -lastfi;
									mi = min(mi,d);
									ma = max(ma,d);
								}
								else {
									ok = false;
									break;
								}
								ptr += lo;
							}
							else {//hi
								if (n - ptr + 1 < hi) {
									ok = false;
									break;
								}
								long long lastx = s[ptr+hi-1] - '0';
								if (s[ptr] == '1' && suf0[ptr+1] >= hi - 2) {
									long long d = 10 - lastfi + lastx;
									mi = min(mi,d);
									ma = max(ma,d);
								}
								else {
									ok = false;
									break;
								}
								ptr += hi;
							}
						}
						else {
							ok = false;
							break;
						}
					}
					if (ok && ptr == n + 1) ans = min(1ll*ans,1ll*ma-mi);
				}
				else {
					if (n % len == 0 && s[1] != '0') {
						long long prefi = gethash(1,len-1);
						long long lastfi = s[len] - '0';
						long long mi = 0, ma = 0;
						bool ok = true;
						for (int i=len+1;i<=n && ma - mi <= ans;i+=len) {
							if (s[i] == '0') {
								ok = false;
								break;
							}
							long long prex = gethash(i,i+len-2);
							long long lastx = s[i+len-1] - '0';
							if (prex == prefi) {
								long long d = lastx - lastfi;
								mi = min(mi,d);
								ma = max(ma,d);
							}
							else if ((prex + 1) % mo == prefi) {
								long long d = -lastfi - (10 - lastx);
								mi = min(mi,d);
								ma = max(ma,d);
							}
							else if (prex == (prefi+1) % mo) {
								long long d = (10 - lastfi) + lastx;
								mi = min(mi,d);
								ma = max(ma,d);
							}
							else {
								ma = 100;
								mi = 0;
								break;
							}
						}
						if (ok) ans = min(1ll*ans,1ll*ma - mi);
					}
					else continue;
				}
			}
			assert(ans >= 0 && ans <= 9);
			printf("%d\n",ans);
		}
	}
	return 0;
}
