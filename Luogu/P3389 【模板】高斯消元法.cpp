#include <cstdio>
#include <cmath>
#include <algorithm>
#define d 1e-8
using namespace std;
double a[110][110],now;
int n;
bool gauss() {
	for (int i=0;i<n;i++) {
		int k=i;
		for (int j=i+1;j<n;j++) if (fabs(a[j][i])>fabs(a[k][i])) k = j;
		now = a[k][i];
		if (fabs(now)<d) return true;
		for (int j=i;j<=n;j++) swap(a[i][j],a[k][j]);
		for (int j=i;j<=n;j++) a[i][j] /= now;
		for (int k=0;k<n;k++) if (k != i) {
			now = a[k][i];
			for (int j=i;j<=n;j++) a[k][j] -= a[i][j]*now;
		}
	}
	return false;
}
int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) for (int j=0;j<=n;j++) scanf("%lf",&a[i][j]);
	if (gauss()) printf("No Solution\n");
	else for (int i=0;i<n;i++) printf("%0.2f\n",a[i][n]);
	return 0;
}
