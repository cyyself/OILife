#include <bits/stdc++.h>
using namespace std;
const long long mo = 1000000007;
int cnt[3];
long long f[2][3];
int n,l,r;
void solve(int x,int d) {
	cnt[0] += (x / 3) * d;
	cnt[1] += ((x+2) / 3) * d;
	cnt[2] += ((x+1) / 3) * d;
}
int main() {
	scanf("%d%d%d",&n,&l,&r);
	solve(r,1);
	solve(l-1,-1);
	//printf("(debug)%d %d %d\n",cnt[0],cnt[1],cnt[2]);
	f[1][0] = cnt[0];
	f[1][1] = cnt[1];
	f[1][2] = cnt[2];
	for (int i=2;i<=n;i++) {
		int cur = i & 1;
		int pre = (i & 1) ^ 1;
		f[cur][0] = ((f[pre][0] * cnt[0]) % mo + (f[pre][1] * cnt[2]) % mo + (f[pre][2] * cnt[1]) % mo) % mo;
		f[cur][1] = ((f[pre][0] * cnt[1]) % mo + (f[pre][1] * cnt[0]) % mo + (f[pre][2] * cnt[2]) % mo) % mo;
		f[cur][2] = ((f[pre][0] * cnt[2]) % mo + (f[pre][1] * cnt[1]) % mo + (f[pre][2] * cnt[0]) % mo) % mo;
	}
	printf("%lld\n",f[n&1][0]);
	return 0;
}
