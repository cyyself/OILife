#include <bits/stdc++.h>
using namespace std;
struct Pos {
	int x1,y1,x2,y2;
}p[20];
long long f[1<<20];
int n;
bool cross(Pos a,Pos b) {
	if ((a.x2 >= b.x1 && a.x2 <= b.x2) || (a.x1 >= b.x1 && a.x1 <= b.x2)) return true;
	swap(a,b);
	if ((a.x2 >= b.x1 && a.x2 <= b.x2) || (a.x1 >= b.x1 && a.x1 <= b.x2)) return true;
	return false;
}
void debug() {

}
long long dfs(int stat) {
	if (f[stat] != -1) return f[stat];
	long long cur = 0;
	for (int i=0;i<n;i++) {
		if (stat & (1 << i)) {
			if (stat == 15 && i == 1) {
				debug();
			}
			//看看底下还有没有未消灭的
			bool exist = false;
			for (int j=0;j<n;j++) {
				if (p[j].x2 == p[i].x1 || p[j].x1 == p[i].x2) continue;
				if ( (stat & (1 << j)) && j != i && p[j].y2 <= p[i].y1) {
					if (cross(p[i],p[j])) exist = true;
				}
			}
			if (!exist) cur += dfs(stat ^ (1 << i));
		}
	}
	f[stat] = cur;
	return f[stat];
}
int main() {
	while (scanf("%d",&n) == 1 && n) {
		memset(f,-1,sizeof(f));
		f[0] = 1;
		for (int i=0;i<n;i++) {
			scanf("%d%d%d%d",&p[i].x1,&p[i].y1,&p[i].x2,&p[i].y2);
		}
		printf("%lld\n",dfs((1<<n)-1));
	}
	return 0;
}
