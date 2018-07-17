#include <bits/stdc++.h>
using namespace std;
int s[55][10];
int sum[10];
double avg[10];
int main() {
	int n,m;
	while (scanf("%d%d",&n,&m) == 2) {
		memset(sum,0,sizeof(sum));
		for (int i=0;i<n;i++) {
			int stusum = 0;
			for (int j=0;j<m;j++) {
				scanf("%d",&s[i][j]);
				sum[j] += s[i][j];
				stusum += s[i][j];
			}
			if (i != 0) printf(" ");
			printf("%0.2lf",(double)stusum/m);
		}
		printf("\n");
		for (int i=0;i<m;i++) {
			avg[i] = (double)sum[i]/n;
			if (i != 0) printf(" ");
			printf("%0.2lf",avg[i]);
		}
		printf("\n");
		int ans = 0;
		for (int i=0;i<n;i++) {
			int j;
			for (j=0;j<m;j++) {
				if (s[i][j]*n < sum[j]) break;
			}
			if (j == m) ans ++;
		}
		printf("%d\n\n",ans);
	}
	return 0;
}