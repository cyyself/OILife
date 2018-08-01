#include <cstdio>
#include <algorithm>
using namespace std;
int f[1005][2];//f[i][j]表示第i个任务
struct T {
	int s,e,w;
	friend bool operator < (const T &a,const T &b) {
		return a.s < b.s;
		/*
		if (a.e < b.e) return true;
		if (a.e == b.e && a.s < b.s) return true;
		return false;
		*/
	}
}t[1005];
int main() {
	int n,m,r;
	scanf("%d%d%d",&n,&m,&r);
	for (int i=1;i<=m;i++) scanf("%d%d%d",&t[i].s,&t[i].e,&t[i].w);
	sort(t+1,t+1+m);
	t[0].e = 0x80000000;
	for (int i=1;i<=m;i++) {
		f[i][0] = max(f[i-1][0],f[i-1][1]);
		for (int j=i-1;j>=0;j--) if (t[j].e + r <= t[i].s) f[i][1] = max(f[i][1],f[j][1]+t[i].w);
	}
	printf("%d\n",max(f[m][0],f[m][1]));
	return 0;
}
