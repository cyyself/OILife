#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int n,k;
struct Pos {
	int x,y,id;
	friend bool operator < (const Pos &a,const Pos &b) {
		if (a.x == b.x) return a.y < b.y;
		return a.x < b.x;
	}
}p[10000];
struct Edge {
	int u,v,w;
	friend bool operator < (const Edge &a,const Edge &b) {
		return a.w < b.w;
	}
}e[40000];
int ecnt;
struct DATA {
	int w;
	int id;
}tr[2002];
inline int lowbit(int x) {
	return x & (-x);
}
void find_vertice(int u,int pos,int w) {
	pos += 1001;
	DATA cur;
	cur.w = INF;
	for (int i=pos;i<=2001;i+=lowbit(i)) if (tr[i].w < cur.w) cur = tr[i];
	if (cur.w != INF) e[ecnt++] = (Edge){u,cur.id,cur.w-w};
}
void insert_vertice(int u,int pos,int w) {
	pos += 1001;
	for (int i=pos;i>=1;i-=lowbit(i)) if (w < tr[i].w) {
		tr[i].w = w;
		tr[i].id = u;
	}
}
void build_graph() {
	memset(tr,0x3f,sizeof(tr));
	sort(p,p+n);
	for (int i=n-1;i>=0;i--) {
		int pos = p[i].y - p[i].x;
		int w = p[i].x + p[i].y;
		find_vertice(p[i].id,pos,w);
		insert_vertice(p[i].id,pos,w);
	}
}
int f[10000];
int find(int x) {
	if (f[x] != x) f[x] = find(f[x]);
	return f[x];
}
void uni(int u,int v) {
	f[find(u)] = find(v);
}
void kruskal() {
	sort(e,e+ecnt);
	int num = n;
	for (int i=0;i<ecnt;i++) {
		if (find(e[i].u) == find(e[i].v)) continue;
		uni(e[i].u,e[i].v);
		if (--num == k) {
			printf("%d\n",e[i].w);
			break;
		}
	}
}
int main() {
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) f[i] = i;
	for (int i=0;i<n;i++) {
		scanf("%d%d",&p[i].x,&p[i].y);
		p[i].id = i;
	}
	build_graph();
	for (int i=0;i<n;i++) swap(p[i].x,p[i].y);
	build_graph();
	for (int i=0;i<n;i++) p[i].y = -p[i].y;
	build_graph();
	for (int i=0;i<n;i++) swap(p[i].x,p[i].y);
	build_graph();
	kruskal();
	return 0;
}
