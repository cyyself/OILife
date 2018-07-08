#include <bits/stdc++.h>
using namespace std;
int n;
struct grape {
	double val[6];
	int no;
}g[65];
double dis[65][65];
int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%d",&g[i].no);
		for (int j=0;j<6;j++) scanf("%lf",&g[i].val[j]);
	}
	int ans = -1;
	double ansv = 0;
	for (int i=0;i<n;i++) {
		double tmp = 0;
		for (int j=0;j<n;j++) {
			if (j == i) continue;
			double dist = 0;
			for (int k=0;k<6;k++) {
				dist += pow(g[i].val[k]-g[j].val[k],2);
			}
			dis[i][j] = sqrt(dist);
			tmp += sqrt(dist);
		}
		if (tmp > ansv) {
			ansv = tmp;
			ans = g[i].no;
		}
	}
	printf("%d\n",ans);
	return 0;
}
