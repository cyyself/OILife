#include <bits/stdc++.h>
using namespace std;
bool f[1005];
int main() {
	for (int i=0;i<=1000;i++) {
		if (!f[i]) for (int j=1;i+j<=1000;j<<=1) {
			f[i+j] = true;
		}
	}
	int n;
	while (scanf("%d",&n) == 1) {
		if (f[n]) printf("Kiki\n");
		else printf("Cici\n");
	}
	return 0;
}
