#include <bits/stdc++.h>
using namespace std;
int d[10];
int main() {
	for (int i=0;i<10;i++) scanf("%d",&d[i]);
	int ans = 0;
	for (int i=0;i<10000;i++) {
		int a[10];
		memset(a,0,sizeof(a));
		a[i%10] |= true;
		a[(i/10)%10] |= true;
		a[(i/100)%10] |= true;
		a[(i/1000)%10] |= true;
		bool ok = true;
		for (int i=0;i<10;i++) if (a[i] != d[i]) ok = false;
		ans += ok;
	}
	printf("%d\n",ans);
	return 0;
}
