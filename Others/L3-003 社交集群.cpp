#include <bits/stdc++.h>
using namespace std;
int f[2001];
int find(int x) {
	if (f[x] != x) f[x] = find(f[x]);
	return f[x];
}
void uni(int x,int y) {
	f[find(x)] = find(y);
}
int main() {
	for (int i=1;i<=2000;i++) f[i] = i;
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		int k;
		scanf("%d:",&k);
		while (k --) {
			int x;
			scanf("%d",&x);
			uni(i,1000+x);
		}
	}
	map <int,int> cnt;
	for (int i=1;i<=n;i++) cnt[find(i)] ++;
	vector <int> ans;
	for (auto x:cnt) ans.push_back(x.second);
	sort(ans.begin(),ans.end());
	reverse(ans.begin(),ans.end());
	cout << ans.size() << endl;
	for (int i=0;i<ans.size();i++) {
		if (i != 0) printf(" ");
		printf("%d",ans[i]);
	}
	cout << endl;
	return 0;
}
