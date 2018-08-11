#include <bits/stdc++.h>
using namespace std;
bool exist[2005][2005];
int main() {
	int xa,ya,xb,yb;
	scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
	if (xa > xb) swap(xa,xb);
	if (ya < yb) swap(ya,yb);
	int n;
	scanf("%d",&n);
	while (n--) {
		int x,y,r;
		scanf("%d%d%d",&x,&y,&r);
		for (int i=x-r;i<=x+r;i++) {
			if (!(i >= xa && i <= xb)) continue;
			int dx = abs(x-i);
			int dy = sqrt(r * r - dx * dx) + 0.5;
			if (dy * dy + dx * dx > r * r) dy --;
			int l = y - dy;
			int r = y + dy;
			if (i == xa || i == xb) {
				l = max(yb,l);
				r = min(ya,r);
				for (int j=l;j<=r;j++) exist[i+1001][j+1001] = true;
			}
			else {
				if (ya >= l && ya <= r) exist[i+1001][ya+1001] = true;
				if (yb >= l && yb <= r) exist[i+1001][yb+1001] = true;
			}
		}
	}
	int cnt = 0;
	for (int i=xa;i<=xb;i++) {
		if (!exist[i+1001][ya+1001]) cnt ++;
		if (!exist[i+1001][yb+1001]) cnt ++;
	}
	for (int i=yb+1;i<=ya-1;i++) {
		if (!exist[xa+1001][i+1001]) cnt ++;
		if (!exist[xb+1001][i+1001]) cnt ++;
	}
	printf("%d\n",cnt);
	return 0;
}
