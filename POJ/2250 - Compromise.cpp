#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
string a[105],b[105];
int c1,c2;
string buf;
int f[105][105];
pair<int,int> pre[105][105];
bool read() {
	c1 = c2 = 0;
	string buf;
	while (cin >> buf) {
		if (buf == "#") break;
		a[++c1] = buf;
	}
	while (cin >> buf) {
		if (buf == "#") break;
		b[++c2] = buf;
	}
	return c1 != 0;
}
int main() {
	while (read()) {
		for (int i=1;i<=c1;i++)
			for (int j=1;j<=c2;j++) {
				if (a[i] == b[j]) {
					f[i][j] = f[i-1][j-1] + 1;
					pre[i][j] = make_pair(i-1,j-1);
				}
				else {
					if (f[i-1][j] > f[i][j-1]) {
						f[i][j] = f[i-1][j];
						pre[i][j] =  make_pair(i-1,j);
					}
					else {
						f[i][j] = f[i][j-1];
						pre[i][j] =  make_pair(i,j-1);
					}
				}
			}
		vector <string> ans;
		pair <int,int> p = make_pair(c1,c2);
		while (p.first != 0 && p.second != 0) {
			pair <int,int> pp = pre[p.first][p.second];
			if (f[p.first][p.second] != f[pp.first][pp.second]) {
				ans.push_back(a[p.first]);
			}
			p = pp;
		}
		for (int i = ans.size() - 1;i>=0;i--) {
			cout << ans[i];
			if (i != 0) cout << " ";
		}
		cout << endl;
	}

	return 0;
}
