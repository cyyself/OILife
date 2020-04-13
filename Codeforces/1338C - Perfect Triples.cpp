#include <bits/stdc++.h>
using namespace std;
void out2bit(int x) {
	for (int i=1;i>=0;i--) printf("%d",(x>>i)&1);
}
int mem[10];
const int mt[4][3] = {
	{0,0,0},
	{1,2,3},
	{2,3,1},
	{3,1,2}
};
long long f[30];
long long pre[30];
int main() {
	f[1] = 3;
	pre[1] = 3;
	int mdep = 1;
	do {
		mdep ++;
		f[mdep] = f[mdep-1] * 4;
		pre[mdep] = pre[mdep-1] + f[mdep];
	}
	while (pre[mdep] < 1e16);
	//mdep = 27
	int T;
	scanf("%d",&T);
	while (T --) {
		long long n;
		scanf("%lld",&n);
		if (n <= 3) {
			printf("%lld\n",n);
			continue;
		}
		int b = 1;
		while (n > pre[b]) b ++;
		vector <int> buf;
		n -= pre[b-1];
		long long ans = 0;
		for (int i=b;i>=1;i--) {
			if (i == 1) {
				ans <<= 2;
				ans |= n?n:3;
				//out2bit(n?n:3);
				for (int j=0;j<buf.size();j++) {
					int pr = mt[buf[j]][n?n-1:2];
					ans <<= 2;
					ans |= pr;
					//out2bit(pr);
				}
			}
			else {
				buf.push_back((n-1) / f[i-1]);
				n = (n - 1) % f[i-1] + 1;
			}
		}
		printf("%lld\n",ans);
		//printf("\n");
	}
	return 0;
}
