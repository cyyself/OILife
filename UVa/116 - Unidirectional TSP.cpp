#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int m,n;
	while(scanf("%d%d",&m,&n) == 2) {
		int matrix[15][105];
		for (int i=0;i<m;i++) for (int j=0;j<n;j++) scanf("%d",&matrix[i][j]);
		int last[15][105];
		for (int i=n-2;i>=0;i--) for (int j=0;j<m;j++) {
			int pos = 0;
			int v = 0x7fffffff;
			if (j == 0) {
				const int seq[] = {0,1,-1};
				for (int k=0;k<3;k++) {
					int curpos = (j + seq[k] + m) % m;
					if (matrix[curpos][i+1] < v) {
						pos = curpos;
						v = matrix[curpos][i+1];
					}
				}
			}
			else if (j == m-1) {
				const int seq[] = {1,-1,0};
				for (int k=0;k<3;k++) {
					int curpos = (j + seq[k] + m) % m;
					if (matrix[curpos][i+1] < v) {
						pos = curpos;
						v = matrix[curpos][i+1];
					}
				}
			}
			else {
				const int seq[] = {-1,0,1};
				for (int k=0;k<3;k++) {
					int curpos = (j + seq[k] + m) % m;
					if (matrix[curpos][i+1] < v) {
						pos = curpos;
						v = matrix[curpos][i+1];
					}
				}
			}
			last[j][i] = pos;
			matrix[j][i] += v;
		}
		int ans = 0x7fffffff;
		int anspos = 0;
		for (int i=0;i<m;i++) {
			if (matrix[i][0] < ans) {
				ans = matrix[i][0];
				anspos = i;
			}
		}
		printf("%d",anspos+1);
		int next = last[anspos][0];
		for (int i=1;i<n;i++) {
			printf(" %d",next+1);
			next = last[next][i];
		}
		printf("\n%d\n",ans);
	}
	return 0;
}