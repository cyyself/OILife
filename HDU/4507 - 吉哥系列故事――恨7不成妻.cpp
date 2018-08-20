#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long num[20];
struct DATA {
	bool vis;
	long long cnt;
	long long sum;
	long long sums;//sum^2
}f[20][7][7];
long long ten[20];//ten[i] = pow(10,i);
long long pow2(long long x) {
	x %= mod;
	return (x*x)%mod;
}
long long mul(long long a,long long b) {
	a %= mod;
	b %= mod;
	return (a*b)%mod;
}
DATA dfs(int dep,int sum,int tot,bool uplimited) {
	DATA ret;
	memset(&ret,0,sizeof(DATA));
	ret.vis = true;
	if (dep == -1) {
		if (sum != 0 && tot != 0) {
			ret.cnt = 1;
		}
		return ret;
	}
	else {
		if (!uplimited && f[dep][sum][tot].vis) return f[dep][sum][tot];
		int up = 9;
		if (uplimited) up = num[dep];
		for (int i=0;i<=up;i++) {
			if (i == 7) continue;
			DATA cur = dfs(dep-1,(sum+i)%7,(tot*10+i)%7,uplimited && i == up);
			ret.cnt += cur.cnt % mod;
			ret.cnt %= mod;
			//ret.sum += i*pow(10,dep)*cur.cnt + cur.sum;
			ret.sum += mul(i,mul(ten[dep],cur.cnt));
			ret.sum %= mod;
			ret.sum += cur.sum % mod;
			ret.sum %= mod;
			//ret.sums += cur.sums + 2*pow(10,dep)*i*cur.sum + pow(pow(10,dep),2) * cur.cnt * pow(i,2);
			ret.sums += cur.sums % mod;
			ret.sums %= mod;
			ret.sums += mul(2,mul(ten[dep],mul(i,cur.sum)));
			ret.sums %= mod;
			ret.sums += mul(pow2(ten[dep]),mul(cur.cnt,pow2(i)));
			ret.sums %= mod;
		}
		if (!uplimited) f[dep][sum][tot] = ret;
		return ret;
	}
}
long long solve(long long x) {
	int len = 0;
	while (x) {
		num[len++] = x % 10;
		x /= 10;
	}
	return dfs(len-1,0,0,true).sums;
}
int main() {
	ten[0] = 1;
	for (int i=1;i<20;i++) ten[i] = ten[i-1] * 10;
	int T;
	scanf("%d",&T);
	while (T --) {
		long long l,r;
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",(solve(r)-solve(l-1)+mod)%mod);
	}
	return 0;
}
