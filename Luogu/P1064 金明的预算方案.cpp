#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
struct Obj {
	int v,p;
	Obj (int _v,int _p):v(_v),p(_p){}
	Obj ():v(0),p(0){}//对于附件直接定义默认值为-1
};
vector <Obj> Link[65];
Obj M[64][3];
int f[32005];
int attach[65] = {0};
int main() {
	int N,m;
	cin >> N >> m;
	for (int i=1;i<=m;i++) {
		int v,p,q;
		cin >> v >> p >> q;
		if (q == 0) {
			M[i][0] = Obj(v,p);
		}//不赋值的时候默认值为-1
		else {
			attach[q]++;
			M[q][attach[q]] = Obj(v,p);
		}
	}
	for (int i=1;i<=m;i++) {
		if (M[i][0].v == 0) continue;
		for (int j=N;j>=M[i][0].v;j--) {//先来处理主件
			f[j] = max(f[j],f[j-M[i][0].v] + M[i][0].v * M[i][0].p);
			if (j >= M[i][0].v + M[i][1].v) f[j] = max(f[j],f[j-M[i][0].v-M[i][1].v] + M[i][0].v * M[i][0].p + M[i][1].v * M[i][1].p);
			if (j >= M[i][0].v + M[i][2].v) f[j] = max(f[j],f[j-M[i][0].v-M[i][2].v] + M[i][0].v * M[i][0].p + M[i][2].v * M[i][2].p);
			if (j >= M[i][0].v + M[i][1].v + M[i][2].v) f[j] = max(f[j],f[j-M[i][0].v-M[i][1].v-M[i][2].v] + M[i][0].v * M[i][0].p + M[i][1].v * M[i][1].p + M[i][2].v * M[i][2].p);
		}
	}
	cout << f[N] << endl;
	return 0;
}