#include <iostream>
#include <algorithm>
using namespace std;
int f[30][30005];
int main(){
	int N,m;
	int v[30];
	int p[30];
	cin >> N >> m;
	for (int i=1;i<=m;i++) cin >> v[i] >> p[i];
	for (int i=1;i<=m;i++){
		for (int j=1;j<=N;j++){
			if (v[i] <= j) f[i][j] = max(f[i-1][j],f[i-1][j-v[i]] + v[i]*p[i]);
			else f[i][j] = f[i-1][j];
		}
	}
	cout << f[m][N] << endl;
	return 0;
}