#include <bits/stdc++.h>
using namespace std;
void work(long long x,vector <long long> (&bit)[3]) {
	int cur = 0;
	while (x) {
		if ((x >> cur) & 1) {
			bit[(1LL << cur)%3LL].push_back(1LL << cur);
			x -= 1LL << cur;
		}
		cur ++;
	}
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		long long x;
		scanf("%lld",&x);
		if (x % 3 == 0) printf("1 %lld\n",x);
		else {
			vector <long long> bit[3];
			work(x,bit);
			if (x % 3 == 1) {
				if (bit[1].size() >= 2) printf("2 %lld %lld\n",x^bit[1][0],x^bit[1][1]);
				else if (bit[1].size() >= 1 && bit[2].size() >= 1) printf("2 %lld %lld\n",x^bit[1][0],bit[1][0]|bit[2][0]);
				else if (bit[2].size() >= 3) printf("2 %lld %lld\n",x^bit[2][0]^bit[2][1],bit[2][0]|bit[2][1]|bit[2][2]);
				else assert(false);
			}
			else if (x % 3 == 2) {
				if (bit[2].size() >= 2) printf("2 %lld %lld\n",x^bit[2][0],x^bit[2][1]);
				else if (bit[2].size() >= 1 && bit[1].size() >= 1) printf("2 %lld %lld\n",x^bit[2][0],bit[1][0]|bit[2][0]);
				else if (bit[1].size() >= 3) printf("2 %lld %lld\n",x^bit[1][0]^bit[1][1],bit[1][0]|bit[1][1]|bit[1][2]);
				else assert(false);
			}
		}
	}
	return 0;
}
