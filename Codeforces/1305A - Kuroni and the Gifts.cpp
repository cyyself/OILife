#include <bits/stdc++.h>
using namespace std;
int a[105],b[105];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=n;i++) scanf("%d",&b[i]);
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		for (int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
		for (int i=1;i<=n;i++) printf("%d%c",b[i],i==n?'\n':' ');
	}
	return 0;
}
