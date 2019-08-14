#include <bits/stdc++.h>
using namespace std;
struct Team {
	char s[11];
	long long p,t;
	friend bool operator < (const Team &a,const Team &b) {
		return a.p > b.p || (a.p == b.p && a.t < b.t);
	}
}t[100005];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		long long n,d;
		scanf("%lld%lld",&n,&d);
		for (int i=1;i<=n;i++) scanf("%s%lld%lld",t[i].s,&t[i].p,&t[i].t);
		sort(t+1,t+1+n);
		long long ans = n * d;
		long long pos = (n * d) / 10LL;
		if (ans % 10LL == 5LL && pos + 1LL <= n) printf("%s\n",t[pos+1].s);
		else printf("Quailty is very great\n");
	}
}
