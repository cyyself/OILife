#include <bits/stdc++.h>
using namespace std;
long long pre[200005];
long long a[200005];
long long m;
long long gausssum(long long n) {
	return n * (n + 1) / 2;
}
bool check(long long n) {
	if (n > 200005) return false;
	long long a = gausssum(n);
	long long b = pre[n];
	return (a - b <= m);
}
int main() {
	int n;
	cin >> n >> m;
	for (int i=0;i<n;i++) {
		int toy;
		scanf("%d",&toy);
		if (toy > 200005) continue;
		a[toy] = toy;
	}
	for (int i=1;i<200005;i++) pre[i] = pre[i-1] + a[i];
	int l = 0;
	int r = 1;
	while (check(r)) r *= 2;
	while (l < r) {
		int mid = (l + r + 1) / 2;
		if (check(mid)) {
			l = mid;
		}
		else {
			r = mid - 1;
		}
	}
	vector <int> out;
	for (int i=1;i<=l;i++) {
		if (a[i]) continue;
		out.push_back(i);
	}
	printf("%lu\n",out.size());
	for (auto each:out) {
		printf("%d ",each);
	}
	bool first = true;
	printf("\n");
	return 0;
}
