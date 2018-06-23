#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		long long a;
		scanf("%lld",&a);
		if (a == 0) {
			printf("0\n");
			continue;
		}
		stack <long long> s;
		while (a != 0) {
			s.push(a % 2333);
			a /= 2333;
		}
		bool first = true;
		while (!s.empty()) {
			if (!first) printf(" ");
			printf("%lld",s.top());
			s.pop();
			first = false;
		}
		printf("\n");
	}
	return 0;
}