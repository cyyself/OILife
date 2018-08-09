#include <cstdio>
using namespace std;
bool vis[1000005];
bool h_semi[1000005];
int sum[1000005];
int main() {
	for (int i=5;i<=1000001;i+=4) {
		for (int j=5;i*j<=1000001;j+=4) {
			if (!vis[i] && !vis[j]) h_semi[i*j] = true;
			else h_semi[i*j] = false;
			vis[i*j] = true;
		}
	}
	for (int i=1;i<=1000001;i++) {
		sum[i] = sum[i-1] + h_semi[i];
	}
	int n;
	while (scanf("%d",&n) == 1 && n) {
		printf("%d %d\n",n,sum[n]);
	}
	return 0;
}
