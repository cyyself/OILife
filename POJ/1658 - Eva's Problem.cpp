#include <cstdio>
using namespace std;
long long a[5];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		for (int i=0;i<4;i++) scanf("%lld",&a[i]);
		if (a[1] - a[0] == a[2] - a[1] && a[2] - a[1] == a[3] - a[2]) {
			a[4] = a[3] + a[1] - a[0];
		}
		else {
			a[4] = a[3] * a[3] / a[2];
		}
		printf("%lld %lld %lld %lld %lld\n",a[0],a[1],a[2],a[3],a[4]);
	}
	return 0;
}
