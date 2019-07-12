#include <bits/stdc++.h>
using namespace std;
char d[150005];
char ans[150005];
struct DATA {
	long long dep,pos;
	friend bool operator < (const DATA &a,const DATA &b) {
		return (a.dep > b.dep) || (a.dep == b.dep && d[a.pos] < d[b.pos]) || (a.dep == b.dep && d[a.pos] == d[b.pos] && a.pos < b.pos);
	}
};
long long n;
void bfs() {
	priority_queue <DATA> q;
	for (int i=0;i<n;i++) q.push((DATA){0,i});
	long long lastdep = -1,lastpos = -1;
	while (!q.empty()) {
		DATA u = q.top();
		q.pop();
		if (lastdep == u.dep && lastpos == u.pos) continue;
		lastdep = u.dep;
		lastpos = u.pos;
		if (d[u.pos] < ans[u.dep]) continue;
		ans[u.dep] = d[u.pos];
		if (u.dep + 1 < n && d[(u.pos*u.pos+1LL)%n] >= ans[u.dep+1]) {
			ans[u.dep+1] = d[(u.pos*u.pos+1LL)%n];
			q.push((DATA){u.dep+1,(u.pos*u.pos+1LL)%n});
		}
	}
}
int main() {
	int T;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++) {
		scanf("%lld",&n);
		scanf("%s",d);
		for (int i=0;i<n;i++) ans[i] = 0;
		bfs();
		printf("Case #%d: ",cas);
		ans[n] = '\0';
		printf("%s\n",ans);
	}
	return 0;
}
