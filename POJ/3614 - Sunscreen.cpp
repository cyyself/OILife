#include <cstdio>
#include <algorithm>
using namespace std;
struct cow {
	int mins,maxs;
	friend bool operator < (const cow &a,const cow &b) {
		if (a.mins > b.mins) return true;
		if (a.mins == b.mins) return a.maxs > b.maxs;
		return false;
	}
}c[2500];
bool vis[2500];
struct lotion {
	int s,c;
	friend bool operator < (const lotion &a,const lotion &b) {
		return a.s > b.s;
	}
}l[2500];
int main() {
	int C,L;
	scanf("%d%d",&C,&L);
	for (int i=0;i<C;i++) scanf("%d%d",&c[i].mins,&c[i].maxs);
	sort(c,c+C);
	for (int i=0;i<L;i++) scanf("%d%d",&l[i].s,&l[i].c);
	sort(l,l+L);
	int ans = 0;
	for (int i=0;i<C;i++) {
		for (int j=0;j<L;j++) {
			if (l[j].c <= 0) continue;
			int s = l[j].s;
			if (c[i].mins <= s && c[i].maxs >= s) {
				ans ++;
				l[j].c --;
				break;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
