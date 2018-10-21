#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		priority_queue <int> pq;
		deque <pair<int,int> > dq;//first->seq second->weight
		int n;
		int seq;
		scanf("%d%d",&n,&seq);
		int cur = 0;
		int myweight;
		for (int i=0;i<n;i++) {
			int t;
			scanf("%d",&t);
			if (i == seq) myweight = t;
			pq.push(t);
			dq.push_back(make_pair(i,t));
		}
		int ans = 0;
		while (!dq.empty()) {
			pair<int,int> cur = dq.front();
			while (cur.second < pq.top()) {
				dq.pop_front();
				dq.push_back(cur);
				cur = dq.front();
			}
			ans ++;
			if (cur.first == seq) 
				break;
			dq.pop_front();
			pq.pop();
		}
		printf("%d\n",ans);
	}
	return 0;
}
