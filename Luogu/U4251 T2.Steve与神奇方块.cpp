#include <iostream>
using namespace std;
int f[1005];
int main(){
	int m,n;
	cin >> m >> n;
	int w[105];
	int s[105];
	for (int i=1;i<=n;i++) cin >> s[i] >> w[i];
	for (int i=1;i<=n;i++) for (int j=s[i];j<=m;j++) f[j] = max(f[j],f[j-s[i]]+w[i]);
	cout << f[m] << endl;
	return 0;
}