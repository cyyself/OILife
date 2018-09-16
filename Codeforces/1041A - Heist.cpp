#include <bits/stdc++.h>
using namespace std;
int main() {
	int MAX = 0;
	int MIN = 0x7fffffff;
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int t;
		scanf("%d",&t);
		MAX = max(t,MAX);
		MIN = min(t,MIN);
	}
	int len = MAX - MIN + 1;
	printf("%d\n",len-n);
	return 0;
}
