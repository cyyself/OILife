#include <bits/stdc++.h>
using namespace std;
int a[100005];
bool f[100005][3][3];
int pre[100005][3][3];
bool check(int pos,int i,int j,int k) {
	int arr[3] = {a[pos-3+i],a[pos-2+j],a[pos-1+k]};
	sort(arr,arr+3);
	return arr[1] == a[pos-1];
}
int ans[100005];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n;
		scanf("%d",&n);
		for (int i=2;i<n;i++) scanf("%d",&a[i]);
		a[0] = a[1] = a[2];
		a[n+1] = a[n] = a[n-1];
		for (int i=2;i<=n;i++) 
			for (int j=0;j<3;j++) 
				for (int k=0;k<3;k++) f[i][j][k] = false;

		for (int j=0;j<3;j++) 
			for (int k=0;k<3;k++) f[2][j][k] = 1;

		for (int i=3;i<=n;i++)
			for (int j=0;j<3;j++)
				for (int k=0;k<3;k++)
					for (int l=0;l<3;l++) if (f[i-1][k][l] && check(i,l,k,j)) {
						f[i][j][k] = true;
						pre[i][j][k] = l;
					}

		bool flag = false;
		int p1,p2;
		for (int j=0;j<3;j++) for (int k=0;k<3;k++) if (f[n][j][k]) {
			flag = true;
			p1 = j;
			p2 = k;
		}
		if (flag) {
			int pos = n;
			while (pos) {
				ans[pos] = a[pos-1+p1];
				int t = pre[pos][p1][p2];
				p1 = p2;
				p2 = t;
				pos --;
			}
			printf("%d",ans[1]);
			for (int i=2;i<=n;i++) printf(" %d",ans[i]);
			printf("\n");
		}
		else printf("-1\n");
	}
	return 0;
}