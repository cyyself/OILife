#include <bits/stdc++.h>
using namespace std;
long long x[2005],y[2005],k[2005],c[2005];
struct Edge {
	int u,v;
	long long w;
	friend bool operator < (const Edge &a,const Edge &b) {
		return a.w < b.w;
	}
}e[2005*2005];
int ecnt;
int f[2005];
int find(int x) {
	if (f[x] == x) return x;
	else return f[x] = find(f[x]);
}
vector <int> con;
vector <pair<int,int> > buf;
int main() {
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld%lld",&x[i],&y[i]);
	for (int i=1;i<=n;i++) scanf("%lld",&c[i]);
	for (int i=1;i<=n;i++) scanf("%lld",&k[i]);
	for (int i=1;i<=n;i++) {
		e[ecnt++] = {0,i,c[i]};
	}
	for (int i=1;i<=n;i++) for (int j=1;j<i;j++) {
		long long cost = (abs(x[i]-x[j]) + abs(y[i]-y[j])) * (k[i] + k[j]);
		e[ecnt++] = {i,j,cost};
	}
	sort(e,e+ecnt);
	for (int i=0;i<=n;i++) f[i] = i;
	int cnt = 0;
	long long ans = 0;
	for (int i=0;i<ecnt && cnt < n + 1;i++) {
		if (find(e[i].u) == find(e[i].v)) continue;
		if (e[i].u == 0) con.push_back(e[i].v);
		else if (e[i].v == 0) con.push_back(e[i].u);
		else buf.push_back(make_pair(e[i].u,e[i].v));
		ans += e[i].w;
		cnt ++;
		f[find(e[i].u)] = find(e[i].v);
	}
	printf("%lld\n",ans);
	printf("%d\n",(int)con.size());
	for (int i=0;i<con.size();i++) printf("%d%c",con[i],i==con.size()-1?'\n':' ');
	printf("%d\n",(int)buf.size());
	for (auto x:buf) printf("%d %d\n",x.first,x.second);
	return 0;
}
