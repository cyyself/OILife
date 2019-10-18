#include <bits/stdc++.h>
using namespace std;
vector <int> vx[100005],vy[100005];
long long n,m,k;
long long work(int init_dir) {
    int l=0,r=m+1,u=0,d=n+1;
	int x = 1, y = 1, dir = init_dir;//0-3
	long long tot = 1;
	bool ans = true;
	while (ans) {
		if (dir == 0) {
			auto tmp = upper_bound(vx[x].begin(),vx[x].end(),y);
			int pos = *tmp;
			pos = min(r,pos);
			u=x;
			tot += pos - y - 1;
			if (pos - y - 1 == 0) ans=false;
			assert(pos-y-1 >= 0);
			y = pos - 1;
			dir = (dir + 1) % 4;
		}
		else if (dir == 1) {
			auto tmp = upper_bound(vy[y].begin(),vy[y].end(),x);
			int pos = *tmp;
			pos = min(d,pos);
			r=y;
			tot += pos - x - 1;
			if (pos - x - 1 == 0) ans=false;
			assert(pos - x - 1 >= 0);
			x = pos - 1;
			dir = (dir + 1) % 4;
		}
		else if (dir == 2) {
			auto tmp = upper_bound(vx[x].begin(),vx[x].end(),y)-1;
			int pos = *tmp;
			pos = max(l,pos);
			d=x;
			tot += y - pos - 1;
			if (y - pos - 1 == 0) ans=false;
			assert(y - pos - 1 >= 0);
			y = pos + 1;
			dir = (dir + 1) % 4;
		}
		else if (dir == 3) {
			auto tmp = upper_bound(vy[y].begin(),vy[y].end(),x)-1;
			int pos = *tmp;
			pos = max(u,pos);
			l=y;
			tot += x - pos - 1;
			if (x - pos - 1 == 0) ans=false;
			assert(x - pos - 1 >= 0);
			x = pos + 1;
			dir = (dir + 1) % 4;
		}
	}
	return tot;
}
int main() {
	scanf("%lld%lld%lld",&n,&m,&k);
	for (int i=0;i<k;i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		vx[x].push_back(y);
		vy[y].push_back(x);
	}
	for (int i=1;i<=n;i++) {
		vx[i].push_back(0);
		vx[i].push_back(m+1);
	}
	for (int i=1;i<=m;i++) {
		vy[i].push_back(0);
		vy[i].push_back(n+1);
	}
	for (int i=1;i<=n;i++) sort(vx[i].begin(),vx[i].end());
	for (int i=1;i<=m;i++) sort(vy[i].begin(),vy[i].end());
	if (work(0) == n * m - k || work(1) == n*m-k) puts("Yes");
	else puts("No");
	return 0;
}
