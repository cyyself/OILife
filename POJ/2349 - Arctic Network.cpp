//double会WA
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct edge {
	int u,v;
	float w;
	edge(int _u,int _v,float _w):u(_u),v(_v),w(_w) {

	}
	edge() {

	}
	friend bool operator < (const edge &a,const edge &b) {
		return a.w < b.w;
	}
}e[250005];
int ecnt;
struct pos {
	float x,y;
}sta[505];
float cal(int i,int j) {
	float dx = sta[i].x - sta[j].x;
	float dy = sta[i].y - sta[j].y;
	return sqrt(dx*dx+dy*dy);
}

int f[505];
int find(int x) {
	if (f[x] == x) return x;
	else {
		f[x] = find(f[x]);
		return f[x];
	}
}
void uni(int i,int j) {
	f[find(i)] = find(j);
}
int main() {
	int n;
	scanf("%d",&n);
	while (n--) {
		int s,p;
		scanf("%d%d",&s,&p);
		//init {
		for (int i=0;i<p;i++) f[i] = i;
		ecnt = 0;
		//init }
		for (int i=0;i<p;i++) {
			scanf("%f%f",&sta[i].x,&sta[i].y);
			for (int j=0;j<i;j++) e[ecnt++] = edge(i,j,cal(i,j));
		}
		sort(e,e+ecnt);
		float ans;
		int ptr = 0;
		for (int i=0;i<p-s;i++) {
			while (find(e[ptr].u) == find(e[ptr].v)) {
				ptr ++;
			}
			uni(e[ptr].u,e[ptr].v);
			ans = e[ptr].w;
		}
		printf("%0.2f\n",ans);
	}
	return 0;
}
