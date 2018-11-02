#include <bits/stdc++.h>
using namespace std;
double p[1005][1005][3];
double f[1005][1005];//期望步数
int main() {
	int r,c;
	while (scanf("%d%d",&r,&c) == 2) {
		memset(f,0,sizeof(f));
		for (int i=1;i<=r;i++) 
			for (int j=1;j<=c;j++) scanf("%lf%lf%lf",&p[i][j][0],&p[i][j][1],&p[i][j][2]);
		for (int i=r;i>=1;i--)
			for (int j=c;j>=1;j--) {
				if (abs(p[i][j][0] - 1) < 1e-5) continue;
				f[i][j] = ((double)2 + f[i][j+1]*p[i][j][1] + f[i+1][j]*p[i][j][2]) / (1 - p[i][j][0]);
			}
		printf("%0.3lf\n",f[1][1]);
	}
	return 0;
}
