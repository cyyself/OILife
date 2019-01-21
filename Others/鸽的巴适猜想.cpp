#include <bits/stdc++.h>
using namespace std;
vector <pair<int,int> > q[2];
vector <int> ls;
int f[200005];
int find(int x) {
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
void uni(int x,int y) {
	f[find(x)] = find(y);
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		q[0].clear();
		q[1].clear();
		ls.clear();
		int n;
		scanf("%d",&n);
		for (int i=0;i<n;i++) {
			int x,y,t;
			scanf("%d%d%d",&x,&y,&t);
			ls.push_back(x);
			ls.push_back(y);
			q[t].push_back(make_pair(x,y));
		}
		sort(ls.begin(),ls.end());
		vector<int>::iterator it = unique(ls.begin(),ls.end());
		ls.erase(it,ls.end());
		for (int i=0;i<ls.size();i++) f[i] = i;
		for (unsigned int i=0;i<q[1].size();i++) {
			q[1][i].first = lower_bound(ls.begin(),ls.end(),q[1][i].first) - ls.begin();
			q[1][i].second = lower_bound(ls.begin(),ls.end(),q[1][i].second) - ls.begin();
			uni(q[1][i].first,q[1][i].second);
		}
		bool ans = true;
		for (unsigned int i=0;i<q[0].size() && ans;i++) {
			q[0][i].first = lower_bound(ls.begin(),ls.end(),q[0][i].first) - ls.begin();
			q[0][i].second = lower_bound(ls.begin(),ls.end(),q[0][i].second) - ls.begin();
			if (find(q[0][i].first) == find(q[0][i].second)) ans = false;
		}
		if (ans) puts("NICE");
		else puts("GG");
	}
	return 0;
}
