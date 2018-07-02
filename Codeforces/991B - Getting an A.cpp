#include <bits/stdc++.h>
int a[105];
int n;
bool check(double sum) {
	double t = sum / n;
	int r = t + 0.5;
	if (r == 5) return true;
	else return false;
}
int main() {
	scanf("%d",&n);
	double sum = 0;
	for (int i=0;i<n;i++) {
		scanf("%d",&a[i]);
		sum += a[i];
	}
	if (check(sum)) {
		printf("0\n");
		return 0;
	}
	std::sort(a,a+n);
	int xg = 0;
	for (int i=0;i<n;i++) {
		sum += 5 - a[i];
		xg ++;
		if (check(sum)) {
			printf("%d\n",xg);
			return 0;
		}
	}
	return 0;
}