#include <bits/stdc++.h>
using namespace std;
int n,m;
int head[200005];
struct Edge {
	int v,w;
	int next;
}e[400005];
int ecnt = 0;
inline void AddEdge(int u,int v,int w) {
	e[ecnt].v = v;
	e[ecnt].w = w;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
inline int read() {
	int f = 1;
	int ret = 0;
	char c = getchar();
	while (!(c >= '0' && c <= '9')) {
		if (c == '-') f = -f;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		ret *= 10;
		ret += c - '0';
		c = getchar();
	}
	return ret * f;
}

bool inq[200005];
int dis[200005];
inline bool spfa(int s) {
	queue <int> q;
	memset(inq,false,sizeof(inq));
	memset(dis,0x3f,sizeof(dis));
	dis[s] = 0;
	q.push(s);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		inq[cur] = false;
		for (int i=head[cur];i != -1;i = e[i].next) {
			int v = e[i].v;
			if (dis[cur] + e[i].w < dis[v]) {
				if (v == s) return false;
				dis[v] = dis[cur] + e[i].w;
				if (!inq[v]) {
					q.push(v);
					inq[v] = true;
				}
			}
		}
	}
	return true;
}
int main() {
	int T;
	T = read();
	while (T--) {
		memset(head,-1,sizeof(head));
		ecnt = 0;
		n = read();
		m = read();
		while (m--) {
			int a,b,w;
			a = read();
			b = read();
			w = read();
			AddEdge(a,b,w);
			if (w >= 0) AddEdge(b,a,w);
		}
		if (spfa(1)) printf("N0\n");
		else printf("YE5\n");
	}
	return 0;
}
