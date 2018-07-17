#include <cstdio>
#include <algorithm>
int n,c;
int x[100005];
bool judge(int d) {
	int ans = 0;
	int last = -1000000000;
	for (int i=0;i<n && ans < c;i++) {
		if (x[i] - last < d) continue;
		ans ++;
		last = x[i];
	}
	return ans >= c;
}
int main() {
	scanf("%d%d",&n,&c);
	for (int i=0;i<n;i++) scanf("%d",&x[i]);
	std::sort(x,x+n);
	int l = 1;
	int r = x[n-1]-x[0];
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (judge(mid)) l = mid;
		else r = mid-1;
	}
	printf("%d\n",l);
	return 0;
}
