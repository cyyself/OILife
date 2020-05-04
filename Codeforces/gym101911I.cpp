#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	scanf("%d",&n);
	int mi = 0x3f3f3f3f,ma = 0;
	for (int i=0;i<n;i++) {
		int x;
		scanf("%d",&x);
		mi = min(mi,x);
		ma = max(ma,x);
	}
	printf("%d\n",(ma - mi + 1) - n);
	return 0;
}
