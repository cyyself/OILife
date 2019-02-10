#include <cstdio>
#include <cstring>
using namespace std;
bool a[5000];
int n;
int work(int k) {
	bool d[5000];
	memset(d,0,n);
	int ans = 0;
	int cur = 0;
	for (int i=0;i<=n-k;i++) {
		cur ^= d[i];
		if (a[i] ^ cur) {
			ans ++;
			cur ^= 1;
			d[i+k] ^= 1;
		}
	}
	for (int i=n-k+1;i<n;i++) {
		cur ^= d[i];
		if (a[i] ^ cur) return 0x3f3f3f3f;
	}
	return ans;
}
int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		char c;
		scanf(" %c",&c);
		if (c == 'B') a[i] = 1;
		else a[i] = 0;
	}
	int ans = 0x3f3f3f3f;
	int ansk = 0;
	for (int k=1;k<=n;k++) {
		int cur = work(k);
		if (cur < ans) {
			ans = cur;
			ansk = k;
		}
	}
	printf("%d %d\n",ansk,ans);
	return 0;
}
