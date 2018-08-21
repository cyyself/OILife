#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		int t,d;
		scanf("%d%d",&t,&d);
		if (t % 2) {
			printf("Case %d: 0\n",c);
			continue;
		}
		else {
			double p = 1;
			double ti = t;
			while (ti > 0) {
				p *= (ti/(ti+1)) * ((ti-1)/ti);
				ti -= 2;
			}
			printf("Case %d: %0.10lf\n",c,p);
		}
	}
	return 0;
}
