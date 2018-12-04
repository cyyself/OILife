#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
float a[100];
int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%f",&a[i]);
	sort(a,a+n);
	float ans = a[n-1];
	for (int i=n-2;i>=0;i--) ans = 2.0 * sqrt(a[i]*ans);
	printf("%0.3f\n",ans);
	return 0;
}
