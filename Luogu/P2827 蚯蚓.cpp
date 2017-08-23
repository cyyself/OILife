#include <cstdio>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
queue <long long> que[3];//0:原始蚯蚓，1:每次切完较短的蚯蚓，2:每次切完较长的蚯蚓
int len[int(7e6+1e5+5)];
inline bool comp(const int &a,const int &b) {
	return a > b;
}
int main() {
	//freopen("earthworm.in","r",stdin);
	//freopen("earthworm.out","w",stdout);
	int n,m,q,u,v,t;
	scanf("%d%d%d%d%d%d",&n,&m,&q,&u,&v,&t);
	for (int i=0;i<n;i++) scanf("%d",&len[i]);
	sort(len,len+n,comp);
	for (int i=0;i<n;i++) que[0].push(len[i]+m*q);
	for (int ti=1;ti<=m;ti++) {
		int select = -1;
		long long length = -1;
		for (int i=0;i<=2;i++) if (!que[i].empty() && que[i].front() > length) {
			length = que[i].front();
			select = i;
		}
		if (select == -1) continue;
		length -= (m - ti + 1) * q;
		que[select].pop();
		int shorter = (length * u) / v;
		que[1].push(shorter + (m - ti) * q);
		que[2].push(length-shorter + (m - ti)*q);
		if (ti % t == 0) printf("%lld ",length);
	}
	printf("\n");
	int p = 0;
	while (!que[0].empty() || !que[1].empty() || !que[2].empty()) {
		p++;
		int select = -1;
		long long length = -1;
		for (int i=0;i<=2;i++) if (!que[i].empty() && que[i].front() > length) {
			length = que[i].front();
			select = i;
		}
		que[select].pop();
		if (p % t == 0) printf("%lld ",length);
	}
	return 0;
}