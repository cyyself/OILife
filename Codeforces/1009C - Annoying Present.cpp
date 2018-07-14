#include <bits/stdc++.h>
using namespace std;
inline long long gausssum(long long x) {
	return (x*(x+1))/2;
}
int main() {
	long long sum = 0;
	long long n,m;
	cin >> n >> m;
	long long each_min = gausssum((n-1LL)/2LL) * 2LL;
	if ( (n - 1LL) % 2LL) each_min += n/2LL;
	long long each_max = gausssum(n-1LL);
	while (m--) {
		long long x,d;
		cin >> x >> d;
		sum += n * x;
		if (d < 0) sum += each_min * d;
		else sum += each_max * d;
	}
	double avg = (double)sum / (double)n;
	printf("%0.15lf\n",avg);
	return 0;
}
