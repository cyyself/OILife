#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
const int maxm = 200;
const int maxn = 17;
pair <char,char> p[maxm];
int f[1<<maxn];
int pre[1<<maxn];
bool check[1<<maxn];
set <char> exist;
map <char,int> mp;
int nodedep[maxn];
int main() {
	int m;
	while (scanf("%d",&m) == 1) {
		mp.clear();
		exist.clear();
		memset(f,0x3f,sizeof(f));
		memset(check,0,sizeof(check));
		for (int i=0;i<m;i++) {
			scanf(" %c %c",&p[i].x,&p[i].y);
			exist.insert(p[i].x);
			exist.insert(p[i].y);
		}
		int n = 0;
		for (auto x:exist) mp[x] = n ++;
		for (int s=1;s<(1<<n);s++) {
			bool ok = true;
			for (int i=0;i<m && ok;i++) {
				if ( ((s >> mp[p[i].x]) & 1) && ((s >> mp[p[i].y]) & 1) ) ok = false;
			}
			if (ok) check[s] = true;
		}
		f[0] = 0;
		for (int s=1;s<(1<<n);s++) {
			for (int s2=s;s2;s2=s&(s2-1)) {
				if (check[s2]) {
					if (f[s^s2] + 1 < f[s]) {
						f[s] = f[s^s2] + 1;
						pre[s] = s ^ s2;
					}
				}
			}
		}
		printf("%d\n",f[(1<<n)-1]-2);
		int s = (1<<n) - 1;
		int dep = 0;
		while (s) {
			int add = s ^ pre[s];
			for (int i=0;i<n;i++) if ((add >> i) & 1) {
				nodedep[i] = dep;
			}
			s = pre[s];
			dep ++;
		}
		for (int i=0;i<m;i++) {
			if (nodedep[mp[p[i].x]] < nodedep[mp[p[i].y]]) swap(p[i].x,p[i].y);
			printf("%c %c\n",p[i].x,p[i].y);
		}
	}
	return 0;
}
