#include <iostream>
using namespace std;
int f[105][10005];
int C[105];
int main() {
	int N,M;
	cin >> N >> M;
	f[0][0] = 1;
	for (int i=1;i<=N;i++) cin >> C[i];
	for (int i=1;i<=N;i++)
		for (int j=0;j<=M;j++) {
			f[i][j] = f[i-1][j];
			if (j >= C[i]) f[i][j] += f[i-1][j-C[i]];
		}
	cout << f[N][M] << endl;
	return 0;
}