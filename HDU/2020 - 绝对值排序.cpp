#include <bits/stdc++.h>
using namespace std;
int a[105];
bool comp(const int &a,const int &b) {
	return abs(a) > abs(b);
}
int main() {
	int n;
	while (scanf("%d",&n) == 1) {
		if (n == 0) break;
		for (int i=0;i<n;i++) scanf("%d",&a[i]);
		sort(a,a+n,comp);
		for (int i=0;i<n;i++) {
			if (i != 0) printf(" ");
			printf("%d",a[i]);
		}
		printf("\n");
	}
	return 0;
}