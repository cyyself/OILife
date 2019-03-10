#include <bits/stdc++.h>
using namespace std;
pair <int,int> c[1001];
int f[1001][1001][2];
int s[1001];
int n,v,x;
int sum(int l,int r) {
	if (l == 0) return s[r];
	return s[r] - s[l-1];
}
int sum_xor(int l,int r) {
	return s[n-1] - sum(l,r);
}
int main() {
	while (scanf("%d%d%d",&n,&v,&x) == 3) {
		for (int i=0;i<n;i++) scanf("%d%d",&c[i].first,&c[i].second);
		c[n++] = make_pair(x,0);
		sort(c,c+n);
		for (int i=0;i<n;i++) s[i] = (i>0?s[i-1]:0) + c[i].second;
		memset(f,0x3f,sizeof(f));
		for (int i=0;i<n;i++) if (c[i].first == x) f[i][i][0] = f[i][i][1] = 0;
		for (int len=2;len<=n;len++) {
			for (int i=0;i+len-1<n;i++) {
				int j = i + len - 1;
				f[i][j][0] = min(f[i][j][0],f[i+1][j][0]+(c[i+1].first-c[i].first)*sum_xor(i+1,j));
				f[i][j][0] = min(f[i][j][0],f[i+1][j][1]+(c[j].first-c[i].first)*sum_xor(i+1,j));
				f[i][j][1] = min(f[i][j][1],f[i][j-1][0]+(c[j].first-c[i].first)*sum_xor(i,j-1));
				f[i][j][1] = min(f[i][j][1],f[i][j-1][1]+(c[j].first-c[j-1].first)*sum_xor(i,j-1));
			}
		}
		printf("%d\n",v*min(f[0][n-1][0],f[0][n-1][1]));
	}
	return 0;
}
