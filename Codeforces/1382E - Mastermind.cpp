#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int ans[maxn];
int n,x,y;
bool work() {
	scanf("%d%d%d",&n,&x,&y);
	map <int,queue<int> > pos;
	map <int,int> cnt;
	for (int i=1;i<=n;i++) {
		int tmp;
		scanf("%d",&tmp);
		cnt[tmp] ++;
		pos[tmp].push(i);
	}
	int unused = 1;
	while (cnt[unused]) unused ++;
	for (int i=1;i<=n;i++) ans[i] = unused;
	priority_queue <pair<int,int> > q;
	for (auto each:cnt) if (each.second) q.push({each.second,each.first});
	int cur_same = 0;
	while (!q.empty() && cur_same < x) {
		auto cur = q.top();
		q.pop();
		cur.first --;
		cur_same ++;
		ans[pos[cur.second].front()] = cur.second;
		pos[cur.second].pop();
		if (cur.first) q.push(cur);
	}
	if (cur_same == x) {
		int cur_diff = 0;
		while (q.size() >= 2 && y - x - cur_diff >= 2) {
			auto a = q.top();
			q.pop();
			auto b = q.top();
			q.pop();
			if (a.first == 1) {
				q.push(a);
				q.push(b);
				break;
			}
			a.first --;
			b.first --;
			ans[pos[a.second].front()] = b.second;
			pos[a.second].pop();
			ans[pos[b.second].front()] = a.second;
			pos[b.second].pop();
			if (a.first) q.push(a);
			if (b.first) q.push(b);
			cur_diff += 2;
		}
		if (cur_diff != y - x) {
			if (y - x - cur_diff == 1) {
				if (q.size() >= 2) {
					auto a = q.top();
					q.pop();     
					auto b = q.top();
					q.pop();
					ans[pos[a.second].front()] = b.second;
					pos[a.second].pop();
					cur_diff ++;
				}
				else return false;
			}
			else {
				vector <pair<int,int> > tmp;
				int cnt = 0;
				int rem = y - x - cur_diff;
				while (!q.empty() && cnt < rem) {
					auto cur = q.top();
					q.pop();
					tmp.push_back({pos[cur.second].front(),cur.second});
					pos[cur.second].pop();
					cnt ++;
				}
				if (cnt == rem) {
					for (int i=0;i<tmp.size();i++) {
						ans[tmp[i].first] = tmp[(i+1)%tmp.size()].second;
					}
					cur_diff += cnt;
				}
				else return false;

			}
		}
		if (cur_diff == y - x) {
			printf("YES\n");
			for (int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
			return true;
		}
		else return false;
	}
	else return false;
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		if (!work()) printf("NO\n");
	}
	return 0;
}
