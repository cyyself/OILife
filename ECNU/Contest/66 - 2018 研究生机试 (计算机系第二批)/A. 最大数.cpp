#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3fffffff;
int main() {
	int n;
	scanf("%d",&n);
	int MAX = -inf;
	while (n--) {
		int t;
		scanf("%d",&t);
		MAX = max(MAX,t);
	}
	printf("%d\n",MAX);
	return 0;
}