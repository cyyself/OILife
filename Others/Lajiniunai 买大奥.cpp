#include <bits/stdc++.h>
using namespace std;
int f[3005];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) {
		int h,t;
		scanf("%d%d",&h,&t);
		for (int j=m;j>=t;j--) {
			f[j] = max(f[j],f[j-t] + h);
		}
	}
	printf("%d\n",f[m]);
	return 0;
}
