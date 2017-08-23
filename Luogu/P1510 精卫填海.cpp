#include <iostream>
#include <algorithm>
using namespace std;
int f[10005];
int main() {
	int v,n,c,ans=-1;
	cin >> v >> n >> c;
	int k[10005];
	int m[10005];
	for (int i=1;i<=n;i++) cin >> k[i] >> m[i];
	for (int i=1;i<=n;i++)
		for (int j=c;j>=m[i];j--) f[j] = max(f[j],f[j-m[i]]+k[i]);
	if (f[c] < v) cout << "Impossible" << endl;
	else {
		int ans = -1;
		for (int j=c;j>=0;j--) if (f[j] >= v) ans = j;
		cout << c-ans << endl;
	}
	return 0;
}