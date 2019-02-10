#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int f[10001];
bool judge[10001];
vector <int> primes;
inline void getprime(int x) {
	judge[1] = true;
	for (int i=2;i<=x;i++) {
		if (!judge[i]) primes.push_back(i);
		for (vector<int>::iterator it=primes.begin();it != primes.end();it ++) {
			int p = *it;
			if (i * p > x) break;
			judge[i*p] = true;
			if (i % p == 0) break;
		}
	}
}
int main() {
	getprime(10000);
	int x;
	while (scanf("%d",&x) && x) {
		queue <int> q;
		q.push(primes[0]);
		int sum = primes[0];
		int cnt = sum == x;
		for (unsigned int i=1;i<primes.size();i++) {
			if (primes[i] > x) break;
			q.push(primes[i]);
			sum += primes[i];
			while (sum > x && q.size() > 1) {
				sum -= q.front();
				q.pop();
			}
			if (sum == x) cnt ++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
