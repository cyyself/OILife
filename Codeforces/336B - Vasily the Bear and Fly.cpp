#include <bits/stdc++.h>
using namespace std;
long long f[100005];
int main() {
	long long m,R;
	cin >> m >> R;
	f[1] = 0;
	f[2] = 4;
	long long d1 = 4;
	long long d2 = 4;
	for (int i=3;i<=m;i++) {
		d1 += 4;
		d2 += d1;
		f[i] = f[i-1] + d2;
	}
	long long dx = f[m];
	long long dy = 2 * m * m;
	long long xie = (m-1)*(m-1)*2;
	dx -= xie;
	dy -= xie;
	double sum = 0;
	sum += (double)dx / (m * m);
	sum += (double)dy / (m * m);
	sum += (sqrt(2) * xie) / (m * m);
	sum *= R;
	printf("%0.10lf\n",sum);
	return 0;
}
