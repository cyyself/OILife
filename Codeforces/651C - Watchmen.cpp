#include <bits/stdc++.h>
using namespace std;
map <int,int> memx;
map <int,int> memy;
map < pair<int,int>,int > cnt;
int main() {
	int n;
	scanf("%d",&n);
	long long ans = 0;
	for (int i=0;i<n;i++) {
		int x,y;
		cin >> x >> y;
		ans += memx[x];
		ans += memy[y];
		ans -= cnt[{x,y}];
		memx[x] ++;
		memy[y] ++;
		cnt[{x,y}] ++;
	}
	cout << ans << endl;
	return 0;
}
