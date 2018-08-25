#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-12;
double c[105][105][105];
struct qp {
	int r,s,p;
	qp (int _r,int _s,int _p) {
		r = _r;
		s = _s;
		p = _p;
	}
};
queue <qp> q;
bool vis[105][105][105];
void bfs(int _r,int _s,int _p) {
	/*
	rock kills scissors
	scissors kill paper
	paper kills a rock
	*/
	c[_r][_s][_p] = 1;
	q.push(qp(_r,_s,_p));
	while (!q.empty()) {
		qp cur = q.front();
		q.pop();
		int r = cur.r;
		int s = cur.s;
		int p = cur.p;
		double rs = r * s;
		double rp = r * p;
		double sp = s * p;
		double sum = r*s + r*p + s*p;
		if (sum == 0) continue;
		if (s) {
			c[r][s-1][p] += c[r][s][p] * rs/sum;
			if (!vis[r][s-1][p]) {
				q.push(qp(r,s-1,p));
				vis[r][s-1][p] = true;
			}
		}
		if (p) {
			c[r][s][p-1] += c[r][s][p] * sp/sum;
			if (!vis[r][s][p-1]) {
				q.push(qp(r,s,p-1));
				vis[r][s][p-1] = true;
			}
		}
		if (r) {
			c[r-1][s][p] += c[r][s][p] * rp/sum;
			if (!vis[r-1][s][p]) {
				q.push(qp(r-1,s,p));
				vis[r-1][s][p] = true;
			}
		}
	}
}
int main() {
	int r,s,p;
	scanf("%d%d%d",&r,&s,&p);
	bfs(r,s,p);
	double ansr = 0;
	double anss = 0;
	double ansp = 0;
	for (int i=1;i<=r;i++) ansr += c[i][0][0];
	for (int i=1;i<=s;i++) anss += c[0][i][0];
	for (int i=1;i<=p;i++) ansp += c[0][0][i];
	printf("%0.10lf %0.10lf %0.10lf\n",ansr,anss,ansp);
	return 0;
}
