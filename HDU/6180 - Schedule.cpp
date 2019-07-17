#include <bits/stdc++.h>
using namespace std;
struct DATA {
	int end;
	int machine;
	friend bool operator < (const DATA &a,const DATA &b) {
		return a.end > b.end;
	}
};
struct DATA2 {
	int end;
	int machine;
	friend bool operator < (const DATA2 &a,const DATA2 &b) {
		return a.end < b.end;
	}
};
int n;
pair <int,int> p[100000];
priority_queue <DATA> q1;
priority_queue <DATA2> q2;
int st[100000];
void work() {
	int need = 0;
	for (int i=0;i<n;i++) {
		while (!q1.empty()) {
			DATA cur = q1.top();
			if (cur.end <= p[i].first) {
				q2.push((DATA2){cur.end,cur.machine});
				q1.pop();
			}
			else break;
		}
		if (q2.empty()) {
			st[need] = p[i].first;
			q1.push((DATA){p[i].second,need});
			need ++;
		}
		else {
			DATA2 cur = q2.top();
			q2.pop();
			q1.push((DATA){p[i].second,cur.machine});
		}
	}
	long long ans = 0;
	while (!q1.empty()) {
		auto cur = q1.top();
		q1.pop();
		ans += (long long)cur.end - st[cur.machine];
	}
	while (!q2.empty()) {
		auto cur = q2.top();
		q2.pop();
		ans += (long long)cur.end - st[cur.machine];
	}
	printf("%d %lld\n",need,ans);
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%d%d",&p[i].first,&p[i].second);
		sort(p,p+n);
		work();
	}
	return 0;
}
