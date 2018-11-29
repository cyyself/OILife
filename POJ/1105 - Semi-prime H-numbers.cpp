#include <cstdio>
bool vis[1000002];
bool h_semi[1000002];
int sum[1000002];
int main() {
	for (int i=5;i<=1000001;i+=4)
		for (int j=5;i*j<=1000001;j+=4) {
			h_semi[i*j] = !vis[i] && !vis[j];
			vis[i*j] = true;
		}
	for (int i=1;i<=1000001;i++) sum[i] = sum[i-1] + h_semi[i];
	int h;
	while (scanf("%d",&h) == 1 && h) printf("%d %d\n",h,sum[h]);
	return 0;
}
