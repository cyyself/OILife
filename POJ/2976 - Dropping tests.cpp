#include <cstdio>
#include <algorithm>
using namespace std;
int n,k;
float a[1005];
float b[1005];
float c[1005];
bool check(float x) {
	for (int i=0;i<n;i++) c[i] = a[i] - x * b[i];
	sort(c,c+n);
	float sum = 0;
	for (int i=0;i<k;i++) sum += c[n-1-i];
	return sum >= 0;
}
int main() {
	while (scanf("%d%d",&n,&k) == 2 && n) {
		k = n - k;
		for (int i=0;i<n;i++) scanf("%f",&a[i]);
		for (int i=0;i<n;i++) scanf("%f",&b[i]);
		float l = 0,r = 1;
		while (r - l > 1e-4) {
			float mid = (l + r) / 2;
			if (check(mid)) l = mid;
			else r = mid;
		}
		printf("%0.0f\n",l*100);
	}
	return 0;
}
