#include <iostream>
using namespace std;
int f[35][20005];
int main() {
	int V,n;
	int w[35];
	cin >> V;
	cin >> n;
	for (int i=1;i<=n;i++) cin >> w[i];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=V;j++) {
			if (w[i] <= j) f[i][j] = max(f[i-1][j],f[i-1][j-w[i]]+w[i]);
			else f[i][j] = f[i-1][j];
		}
	cout << V - f[n][V] << endl;
	return 0;
}