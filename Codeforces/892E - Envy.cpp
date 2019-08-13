#include <bits/stdc++.h>
using namespace std;
struct UUS {//可撤销并查集
	int f[500005],rank[500005];
	stack < pair<int*,int> > s;
	void init(int n) {
		for (int i=1;i<=n;i++) {
			f[i] = i;
			rank[i] = 0;
		}
	}
	int find(int x) {
		while (f[x] != x) x = f[x];
		return x;
	}
	void uni(int x,int y) {
		x = find(x);
		y = find(y);
		if (x == y) {
			s.push({NULL,0});
			s.push({NULL,0});
		}
		else {
			if (rank[x] == rank[y]) {
				s.push({&f[x],f[x]});
				f[x] = y;
				s.push({&rank[y],rank[y]});
				rank[y] ++;
			}
			else {
				if (rank[x] < rank[y]) {
					s.push({&f[x],f[x]});
					f[x] = y;
				}
				else {
					s.push({&f[y],f[y]});
					f[y] = x;
				}
				s.push({NULL,0});
			}
		}
	}
	void undo() {
		auto cur = s.top();
		if (cur.first != NULL) *(cur.first) = cur.second;
		s.pop();
		cur = s.top();
		if (cur.first != NULL) *(cur.first) = cur.second;
		s.pop();
	}
}uus;
bool ans[500005];
struct Edge {
	int u,v,w,id;
	friend bool operator < (const Edge &a,const Edge &b) {
		return a.w < b.w;
	}
};
vector <Edge> e[500005];
Edge* e2[500005];//对于边的编号查询边
set <int> in_query[500005];//存在某个边权的查询
vector <Edge> each_edge[500005];//每个查询所含有的边
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	uus.init(n);
	for (int i=0;i<m;i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[w].push_back({u,v,w,i+1});
	}
	for (int i=1;i<=500000;i++) {
		for (int j=0;j<e[i].size();j++) e2[e[i][j].id] = &e[i][j];
	}
	int q;
	scanf("%d",&q);
	for (int i=1;i<=q;i++) {
		int k;
		scanf("%d",&k);
		for (int j=1;j<=k;j++) {
			int x;
			scanf("%d",&x);
			in_query[e2[x]->w].insert(i);
			each_edge[i].push_back(*(e2[x]));
		}
		sort(each_edge[i].begin(),each_edge[i].end());
	}
	for (int w=1;w<=500000;w++) {
		for (auto qi:in_query[w]) {//查询每个query
			if (ans[qi]) continue;
			int cnt = 0;
			auto st = lower_bound(each_edge[qi].begin(),each_edge[qi].end(),(Edge){0,0,w,0});
			for (auto i=st;i != each_edge[qi].end() && i->w == w;i++) {
				int x = uus.find(i->u);
				int y = uus.find(i->v);
				if (x == y) {
					ans[qi] = true;
					break;
				}
				else {
					uus.uni(x,y);
					cnt ++;
				}
			}
			while (cnt) {
				uus.undo();
				cnt --;
			}
		}
		for (auto edge:e[w]) {
			uus.uni(edge.u,edge.v);
		}
	}
	for (int i=1;i<=q;i++) {
		if (ans[i]) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
