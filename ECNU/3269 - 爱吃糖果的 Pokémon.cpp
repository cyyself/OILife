#include <bits/stdc++.h>
using namespace std;
const int inf = 0x0fffffff;
struct candy{
	int type;
	int time;
	friend bool operator < (const candy &a,const candy &b) {
		if (a.time > b.time) return true;
		if (a.time == b.time && a.type > b.type) return true;
		return false;
	}
	candy(int _type,int _time) {
		type = _type;
		time = _time;
	}
};
priority_queue <candy> q;
queue <int> ans_type;
int main() {
	int n,r,m;
	scanf("%d%d%d",&n,&r,&m);
	for (int i=1;i<=n;i++) q.push(candy(i,-inf));
	int lastcandy_type = -1;
	int ans = 0;
	for (int t=0;t<m;t++) {
		if (!q.empty()) {
			candy cur = q.top();
			if (t - cur.time > r || lastcandy_type == -1) {
				if (!q.empty() && t - cur.time > r) ans ++;
				if (!q.empty()) q.pop();
				if (lastcandy_type != -1) q.push(candy(lastcandy_type,t-1));
				lastcandy_type = cur.type;
			}
		}
		ans_type.push(lastcandy_type);
	}
	printf("%d\n",ans);
	while (!ans_type.empty()) {
		printf("%d ",ans_type.front());
		ans_type.pop();
	}
	return 0;
}
