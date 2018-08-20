#include <bits/stdc++.h>
using namespace std;
vector <long long> e[3005];
int n,m;
long long getans(int h) {
	long long curh = e[1].size();
	long long res = 0;
	vector <long long> backup;
	for (int i=2;i<=m;i++) {
		int sz = e[i].size();
		for (int j=0;j<sz;j++) {
			if (j < sz-(h-1)) {
				res += e[i][j];
				curh ++;
			}
			else backup.push_back(e[i][j]);
		}
	}
	sort(backup.begin(),backup.end());
	for (int i=0;i<backup.size() && curh < h;i++) {
		res += backup[i];
		curh ++;
	}
	return res;
}
int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) {
		long long pi,ci;
		cin >> pi >> ci;
		e[pi].push_back(ci);
	}
	for (int i=1;i<=m;i++) sort(e[i].begin(),e[i].end());
	long long ans = 0x7fffffffffffffff;
	for (int i=1;i<=n;i++) {
		long long tmp = getans(i);
		if (tmp < ans) ans = tmp;
	}
	cout << ans << endl;
	return 0;
}
