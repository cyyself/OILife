#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
int n,m,k,q;
long long b[200005];
long long l[200005],r[200005];
long long pos[200005][4];
long long f[200005][4];
int main() {
	memset(f,0x3f,sizeof(f));
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for (int i=1;i<=n;i++) {
		l[i] = INF;
		r[i] = 0;
	}
	while (k --) {
		long long x,y;
		scanf("%lld%lld",&x,&y);
		l[x] = min(l[x],y);
		r[x] = max(r[x],y);
	}
	for (int i=0;i<q;i++) scanf("%lld",&b[i]);
	sort(b,b+q);
	pos[0][0] = pos[0][1] = pos[0][2] = pos[0][3] = 1;
	f[0][0] = f[0][1] = f[0][2] = f[0][3] = -1;
	for (int i=1;i<=n;i++) {
		if (l[i] == INF) {
			if (i == 1) {
				pos[i][0] = pos[i][1] = pos[i][2] = pos[i][3] = b[0];
			}
			else {
				pos[i][0] = pos[i-1][0];
				pos[i][1] = pos[i-1][1];
				pos[i][2] = pos[i-1][2];
				pos[i][3] = pos[i-1][3];
			}
		}
		else {
			int id1 = lower_bound(b,b+q,l[i])-b - 1;
			if (id1 < 0) id1 = 0;
			pos[i][0] = b[id1];
			pos[i][1] = b[id1+1<q?id1+1:id1];
			int id2 = lower_bound(b,b+q,r[i])-b - 1;
			if (id2 < 0) id2 = 0;
			pos[i][2] = b[id2];
			pos[i][3] = b[id2+1<q?id2+1:id2];
		}
	}
	for (int i=1;i<n;i++) {
		if (l[i] == INF) {
			f[i][0] = f[i-1][0] + 1 + abs(pos[i][0] - pos[i-1][0]);
			f[i][1] = f[i-1][1] + 1 + abs(pos[i][1] - pos[i-1][1]);
			f[i][2] = f[i-1][2] + 1 + abs(pos[i][2] - pos[i-1][2]);
			f[i][3] = f[i-1][3] + 1 + abs(pos[i][3] - pos[i-1][3]);
		}
		else {
			for (int j=0;j<4;j++) {
				for (int k=0;k<4;k++) {
					f[i][j] = min(f[i][j],min(
						f[i-1][k]+1+abs(r[i]-pos[i-1][k])+(r[i]-l[i])+abs(pos[i][j]-l[i]),
						f[i-1][k]+1+abs(l[i]-pos[i-1][k])+(r[i]-l[i])+abs(pos[i][j]-r[i])
						));
				}
			}
		}
	}
	long long ans = INF;
	while (l[n] == INF) n--;
	for (int j=0;j<4;j++) ans = min(ans,
		min(f[n-1][j]+1+abs(r[n]-pos[n-1][j])+(r[n]-l[n]),
			f[n-1][j]+1+abs(l[n]-pos[n-1][j])+(r[n]-l[n]))
	);
	printf("%lld\n",ans);
	return 0;
}
