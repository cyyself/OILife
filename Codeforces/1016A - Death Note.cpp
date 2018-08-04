#include <bits/stdc++.h>
using namespace std;
int main() {
	long long sum = 0;
	long long last = 0;
	long long n,m;
	cin >> n >> m;
	for (int i=0;i<n;i++) {
		long long t;
		cin >> t;
		sum += t;
		if (i != 0) printf(" ");
		cout << sum/m-last;
		last = sum/m;
	}
	printf("\n");
	return 0;
}
