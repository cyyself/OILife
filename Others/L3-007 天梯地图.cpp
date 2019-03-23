//https://pintia.cn/problem-sets/994805046380707840/problems/994805051153825792
#include <bits/stdc++.h>
using namespace std;
struct DATA {
	int v;
	int d,t;
	DATA (int _v,int _d,int _t) {
		v = _v;
		d = _d;
		t = _t;
	}
};
vector <DATA> g[505];
int pre[505];
int tc[505];
int dis[505];
bool inq[505];
void spfa1(int s) {
	memset(pre,-1,sizeof(pre));
	memset(tc,0x3f,sizeof(tc));
	memset(dis,0x3f,sizeof(dis));
	tc[s] = 0;
	dis[s] = 0;
	queue <int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		inq[u] = false;
		q.pop();
		for (auto x:g[u]) {
			if (tc[u] + x.t < tc[x.v]) {
				tc[x.v] = tc[u] + x.t;
				dis[x.v] = dis[u] + x.d;
				pre[x.v] = u;
				if (!inq[x.v]) {
					q.push(x.v);
					inq[x.v] = true;
				}
			}
			else if (tc[u] + x.t == tc[x.v] && dis[u] + x.d < dis[x.v]) {
				dis[x.v] = dis[u] + x.d;
				pre[x.v] = u;
				if (!inq[x.v]) {
					q.push(x.v);
					inq[x.v] = true;
				}
			}
		}
	}
}
void spfa2(int s) {
	memset(pre,-1,sizeof(pre));
	memset(tc,0x3f,sizeof(tc));
	memset(dis,0x3f,sizeof(dis));
	tc[s] = 0;
	dis[s] = 0;
	queue <int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		inq[u] = false;
		q.pop();
		for (auto x:g[u]) {
			if (dis[u] + x.d < dis[x.v]) {
				dis[x.v] = dis[u] + x.d;
				tc[x.v] = tc[u] + 1;
				pre[x.v] = u;
				if (!inq[x.v]) {
					q.push(x.v);
					inq[x.v] = true;
				}
			}
			else if (dis[u] + x.d == dis[x.v] && tc[u] + 1 < tc[x.v]) {
				tc[x.v] = tc[u] + 1;
				pre[x.v] = u;
				if (!inq[x.v]) {
					q.push(x.v);
					inq[x.v] = true;
				}
			}
		}
	}
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		int v1,v2,o,d,ti;
		scanf("%d%d%d%d%d",&v1,&v2,&o,&d,&ti);
		g[v1].push_back(DATA(v2,d,ti));
		if (!o) g[v2].push_back(DATA(v1,d,ti));
	}
	int s,t;
	scanf("%d%d",&s,&t);
	spfa1(s);
	int t_o = tc[t];
	vector <int> path1;
	int cur = t;
	while (cur != -1) {
		path1.push_back(cur);
		cur = pre[cur];
	}
	reverse(path1.begin(),path1.end());
	spfa2(s);
	int d_o = dis[t];
	vector <int> path2;
	cur = t;
	while (cur != -1) {
		path2.push_back(cur);
		cur = pre[cur];
	}
	reverse(path2.begin(),path2.end());
	bool flag = path1.size() == path2.size();
	if (flag) {
		for (int i=0;i<path1.size() && flag;i++) {
			if (path1[i] != path2[i]) flag = false;
		}
	}
	if (flag) {
		printf("Time = %d; Distance = %d: %d",t_o,d_o,s);
		for (int i=1;i<path1.size();i++) printf(" => %d",path1[i]);
		printf("\n");
	}
	else {
		printf("Time = %d: %d",t_o,s);
		for (int i=1;i<path1.size();i++) printf(" => %d",path1[i]);
		printf("\n");
		printf("Distance = %d: %d",d_o,s);
		for (int i=1;i<path2.size();i++) printf(" => %d",path2[i]);
		printf("\n");
	}
	return 0;
}
