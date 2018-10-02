#include <cstdio>
#include <vector>
using namespace std;
vector <int> primes;
bool judge[10000];
void GetPrimes(int range) {
	judge[1] = true;
	for (int i=2;i<=range;i++) {
		if (!judge[i]) primes.push_back(i);
		for (vector<int>::iterator it=primes.begin();it != primes.end();it++) {
			int p = *it;
			if (i * p > range) break;
			judge[i*p] = true;
			if (i % p == 0) break;
		}
	}
}
bool findans;
const int xs[4] = {1000,100,10,1};
void dfs(int dep,int cur,int dst) {
	if (dep == 0) {
		if (cur == dst) findans = true;
		return;
	}
	int digit[4] = {(cur/1000)%10,(cur/100)%10,(cur/10)%10,cur%10};
	for (int i=0;i<4 && !findans;i++) {
		for (int j=(i==0?1:0);j<=9 && !findans;j++) {
			if (j == digit[i]) continue;
			int nxt = cur - xs[i] * digit[i] + xs[i] * j;
			if (!judge[nxt]) dfs(dep-1,nxt,dst);
		}
	}
}
int main() {
	GetPrimes(9999);
	int T;
	scanf("%d",&T);
	while (T --) {
		int a,b;
		scanf("%d%d",&a,&b);
		int ans = -1;
		findans = false;
		do {
			ans ++;
			dfs(ans,a,b);
		} while(!findans && ans < 10);
		if (!findans) printf("Impossible\n");
		else printf("%d\n",ans);
	}
	return 0;
}
