#include <bits/stdc++.h>
using namespace std;
int a[10];
int main() {
	int v;
	scanf("%d",&v);
	int min_digit,min_w = 0x7fffffff;
	for (int i=1;i<=9;i++) {
		scanf("%d",&a[i]);
		if (a[i] <= min_w) {
			min_w = a[i];
			min_digit = i;
		}
	}
	int num = v / min_w;
	if (num == 0) {
		puts("-1");
	}
	else {
		for (int j=0;j<num;j++) {
			bool ok = false;
			for (int i=9;i>min_digit && !ok;i--) if (a[i] - min_w <= v % min_w) {
				v -= a[i];
				printf("%d",i);
				ok = true;
			}
			if (!ok) {
				printf("%d",min_digit);
				v -= min_w;
			}
		}
		printf("\n");
	}
	return 0;
}
