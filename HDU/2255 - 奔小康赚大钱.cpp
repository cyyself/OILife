#include <bits/stdc++.h>
using namespace std;
const int maxn = 305;
const long long inf = 0x3f3f3f3f;
struct Matrix {
	int n;
	long long a[maxn][maxn];
};
struct KM:Matrix {
	long long hl[maxn],hr[maxn],slk[maxn];
	int fl[maxn],fr[maxn],pre[maxn];
	bool vl[maxn],vr[maxn];
	queue <int> q;
	bool check(int i) {
		vl[i] = 1;
		if (fl[i] != -1) {
			q.push(fl[i]);
			vr[fl[i]] = true;
			return true;
		}
		while (i != -1) {
			fl[i] = pre[i];
			swap(i,fr[fl[i]]);
		}
		return 0;
	}
	void bfs(int s) {
		memset(slk,0x3f,sizeof(slk));
		memset(vl,0,sizeof(vl));
		memset(vr,0,sizeof(vr));
		while (!q.empty()) q.pop();
		q.push(s);
		vr[s] = true;
		while (true) {
			long long d;
			while (!q.empty()) {
				for (int i=0,j=q.front();i<n;i++) {
					d = hl[i] + hr[j] - a[i][j];
					if (!vl[i] && slk[i] >= d) {
						pre[i] = j;
						if (d) slk[i] = d;
						else if (!check(i)) return;
					}
				}
				q.pop();
			}
			d = inf;
			for (int i=0;i<n;i++) 
				if (!vl[i] && d > slk[i]) d = slk[i];
			for (int i=0;i<n;i++) {
				if (vl[i]) hl[i] += d;
				else slk[i] -= d;
				if (vr[i]) hr[i] -= d;
			}
			for (int i=0;i<n;i++) 
				if (!vl[i] && slk[i] == 0 && !check(i)) return;
		}
	}
	void ask() {
		memset(pre,-1,sizeof(pre));
		memset(fl,-1,sizeof(fl));
		memset(fr,-1,sizeof(fr));
		memset(hl,0,sizeof(hl));
		memset(hr,0,sizeof(hr));
		for (int i=0;i<n;i++) 
			for (int j=0;j<n;j++) hl[i] = max(hl[i],a[i][j]);
		for (int i=0;i<n;i++) bfs(i);
	}
}km;
int main() {
	int n;
	while (scanf("%d",&n) == 1) {
		for (int i=0;i<n;i++) 
			for (int j=0;j<n;j++) scanf("%lld",&km.a[i][j]);
		km.n = n;
		km.ask();
		long long ans = 0;
		for (int i=0;i<n;i++) ans += km.a[i][km.fl[i]];
		printf("%lld\n",ans);
	}
	return 0;
}
