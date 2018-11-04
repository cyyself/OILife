#include <bits/stdc++.h>
using namespace std;
bool judge[1000005];
vector <int> prime;
void InitPrimes(int n) {
	for (int i=2;i<=n;i++) {
		if (!judge[i]) prime.push_back(i);
		for (auto p:prime) {
			if (i * p > n) break;
			judge[i*p] = true;
			if (i % p == 0) break;
		}
	}
}
double mem[1000005];
double f(int x) {
	if (x == 1) return 0;
	if (mem[x] != 0) return mem[x];
	int cnt = 0;
	int validcnt = 0;
	double tmp = 0;
	for (auto y:prime) {
		if (y > x) break;
		cnt ++;
		if (x % y == 0) {
			tmp += f(x/y);
			validcnt ++;
		}
	}
	return mem[x] = (tmp + cnt) / validcnt;
}
int main() {
	InitPrimes(1000000);
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		int n;
		scanf("%d",&n);
		printf("Case %d: %0.10lf\n",c,f(n));
	}
	return 0;
}
