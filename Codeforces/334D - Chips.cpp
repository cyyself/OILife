#include <bits/stdc++.h>
using namespace std;
bool b_x[1005],b_y[1005];
int n,m;
int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		x --;
		y --;
		b_x[x] = true;
		b_y[y] = true;
	}
	int ans = 0;
	for (int i=1;i<n-1;i++) {
		if (b_x[i] && b_y[i]) continue;
		if (!b_x[i] && !b_y[i]) ans += 2;
		else ans ++;
	}
	if (n % 2 == 1) {
		int mid = n / 2;
		if (!b_x[mid] && !b_y[mid]) ans --;
	}
	printf("%d\n",ans);
	return 0;
}
