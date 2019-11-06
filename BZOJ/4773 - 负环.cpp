#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct Matrix {
	int arr[305][305];
	Matrix() {
		memset(arr,0x3f,sizeof(arr));
	}
}p;
int n,m;
Matrix trans(const Matrix &a,const Matrix &b) {
	Matrix res;
	for (int i=1;i<=n;i++) res.arr[i][i] = 0;
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
	for (int i=1;i<=n;i++) p.arr[i][i] = 0;
	for (int i=0;i<m;i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		p.arr[u][v] = min(p.arr[u][v],w);
	}
	int ans = 0;
	Matrix tmp;
	for (int i=1;i<=n;i++) tmp.arr[i][i] = 0;
	for (int i=1;i<=n && !ans;i++) {
		tmp = trans(tmp,p);
		if (check(tmp)) {
			ans = i;
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
