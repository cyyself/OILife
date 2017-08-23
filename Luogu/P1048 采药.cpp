#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int T,M;
	cin >> T >> M;
	int t[105];
	int v[105];
	int f[105][1005];
	for (int i=1;i<=M;i++) cin >> t[i] >> v[i];
	for (int i=1;i<=M;i++){
		for (int j=1;j<=T;j++){
			if (t[i] <= j){
				f[i][j] = max(f[i-1][j],f[i-1][j-t[i]]+v[i]);
			}
			else f[i][j] = f[i-1][j];
		}
	}
	cout << f[M][T] << endl;
	return 0;
}