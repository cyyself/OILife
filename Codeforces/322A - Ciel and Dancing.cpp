#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%d\n",m+n-1);
	for (int i=1;i<=m;i++) printf("1 %d\n",i);
	for (int i=2;i<=n;i++) printf("%d 1\n",i);
	return 0;
}
