#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main() {
	int n;
	scanf("%d",&n);
	int last = 0;
	for (int i=1;i<=n;i++) {
		int b;
		scanf("%d",&b);
		if (b >= 0) {
			last += b;
			a[i] = last;
		}
		else a[i] = last + b;
	}
	for (int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
	return 0;
}
