#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct Matrix {
	int arr[305][305];
	Matrix() {
		memset(arr,0x3f,sizeof(arr));
		for (int i=0;i<305;i++) arr[i][i] = 0;
	}
}p[10],s[10];
int n,m;
Matrix trans(const Matrix &a,const Matrix &b) {
	Matrix res;
	for (int i=1;i<=n;i++) for (int k=1;k<=n;k++) for (int j=1;j<=n;j++) {
		res.arr[i][j] = min(res.arr[i][j],a.arr[i][k] + b.arr[k][j]);
	}
	return res;
}
bool check(const Matrix &a) {
	for (int i=1;i<=n;i++) if (a.arr[i][i] < 0) return true;
	return false;
}
int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) p[0].arr[i][i] = 0;
	for (int i=0;i<m;i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		p[0].arr[u][v] = min(p[0].arr[u][v],w);
	}
	int r = 0;
	for (int j=1;(1<<j)<=n;j++) {
		p[j] = trans(p[j-1],p[j-1]);
		s[j] = trans(s[j-1],p[j-1]);
		r = j;
	}
	int ans = 0;
	Matrix pre;
	for (int j=r;j>=0;j--) {
		if (!check(trans(pre,s[j]))) {
			ans |= 1 << j;
			pre = trans(pre,p[j]);
		}
	}
	if (check(pre)) printf("%d\n",ans);
	else printf("0\n");
	return 0;
}
