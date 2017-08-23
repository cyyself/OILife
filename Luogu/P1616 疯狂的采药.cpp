#include <iostream>
using namespace std;
int t[10005];
int m[100005];
int f[100005];
int main() {
	int T,M;
	cin >> T >> M;
	for (int i=1;i<=M;i++) cin >> t[i] >> m[i];
	for (int i=1;i<=M;i++)
		for (int j=t[i];j<=T;j++) f[j] = max(f[j],f[j-t[i]]+m[i]);
	cout << f[T] << endl;
	return 0;
}