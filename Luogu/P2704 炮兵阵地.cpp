#include <bits/stdc++.h>
using namespace std;
int s[65];//只有60个合法状态
int scnt = 0;
int f[105][65][65];
int matrix[105];
inline bool judgex(int x) {
	if (x & (x << 1)) return false;
	if (x & (x << 2)) return false;
	return true;
}
inline bool judgey(int x,int y) {
	if (x & y) return false;
	return true;
}
inline int getn(int x) {
	int ret = 0;
	while (x) {
		ret += x & 1;
		x = x >> 1;
	}
	return ret;
}
int main() {
	int n,m;
	cin >> n >> m;
	for (int i=0;i<n;i++) 
		for (int j=0;j<m;j++) {
			char t;
			cin >> t;
			if (t == 'H') matrix[i] += (1 << j);
		}
	
	for (int i=0;i<(1<<m);i++) if (judgex(i)) s[scnt++] = i;
	for (int i=0;i<scnt;i++) if (judgey(s[i],matrix[0])) f[0][i][0] = getn(s[i]);
	for (int i=1;i<n;i++) {
		for (int j=0;j<scnt;j++) {
			if (!judgey(s[j],matrix[i])) continue;
			int jn = getn(s[j]);
			for (int k=0;k<scnt;k++) {
				if (!judgey(s[j],s[k])) continue;
				for (int l=0;l<scnt;l++) {
					if (!judgey(s[j],s[l])) continue;
					f[i][j][k] = max(f[i][j][k],f[i-1][k][l] + jn);
				}
			}
		}
	}
	int ans = 0;
	for (int i=0;i<scnt;i++)
		for (int j=0;j<scnt;j++) ans = max(ans,f[n-1][i][j]);
	cout << ans << endl;
	return 0;
}