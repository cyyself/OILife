#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
int f[1<<18];
int l[20][20];
int n;
struct pos {
	double x,y;
}p[20];
struct fc {
	double a,b,y;//y=ax2+bx中，a,b的系数
	fc(double _a,double _b,double _y) {
		a = _a;
		b = _b;
		y = _y;
	}
	fc():a(0),b(0),y(0){}
};
bool equal(double x,double y) {
	if (fabs(x-y) < eps) return true;
	else return false;
}
bool jfc(fc a,fc b,double &jiea,double &jieb) {
	double cheng = b.b / a.b;
	a.a *= cheng;
	a.b *= cheng;
	a.y *= cheng;
	if (equal(a.a,b.a) && equal(a.y,b.y)) return false;
	jiea = (a.y - b.y) / (a.a - b.a);
	if (jiea >= 0) return false;
	if (equal(a.a-b.a,0)) return false;
	jieb = (a.y - jiea * a.a) / a.b;
	return true;
}
void pause_for_debug() {

}
int dfs(int stat) {
	if (f[stat] != INF) return f[stat];
	if (__builtin_popcount(stat) <= 1) return __builtin_popcount(stat);
	for (int i=0;i<n;i++) if (stat & (1 << i)) {
		f[stat] = min(f[stat],dfs(stat ^ (1 << i))+1);
		for (int j=0;j<n;j++) 
			if (j != i && stat & (1 << j) && l[i][j] != 0) {
				f[stat] = min(f[stat],dfs(stat&(~l[i][j]))+1);
			}
	}
	return f[stat];
}
int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		memset(f,0x3f,sizeof(f));
		memset(l,0,sizeof(l));
		int m;
		scanf("%d%d",&n,&m);
		for (int i=0;i<n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
		for (int i=0;i<n;i++)
			for (int j=i+1;j<n;j++) {
				double jiea,jieb;
				if (
					jfc(
						fc(p[i].x*p[i].x,p[i].x,p[i].y),
						fc(p[j].x*p[j].x,p[j].x,p[j].y),
						jiea,
						jieb
						)
					){
					l[i][j] = (1 << i) | (1 << j);
					for (int k=j+1;k<n;k++) if (equal(p[k].y,jiea*pow(p[k].x,2)+jieb*p[k].x)) l[i][j] |= (1 << k);
				}
				l[j][i] = l[i][j];
			}
		printf("%d\n",dfs((1 << n)-1));
	}
	return 0;
}
