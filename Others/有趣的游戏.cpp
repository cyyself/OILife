#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n,m;
		scanf("%d%d",&n,&m);
		if (n + m == 2) puts("Bob");
		else puts("Alice");
	}
	return 0;
}
