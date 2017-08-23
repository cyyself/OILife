#include <cstdio>
#include <algorithm>
using namespace std;
int a[100001];
int n,x,ans;
int main() {
	scanf("%d%d",&x,&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int i = 0;
	a[n+1] = 0x7fffffff;
	for (int j=1;j<=n && i < x;) {
		if (a[j+1]<=i+1) j++;
		else {
			i += a[j];
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}