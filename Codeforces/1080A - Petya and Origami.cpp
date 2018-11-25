#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	int a[3] = {2*n,5*n,8*n};
	for (int i=0;i<3;i++) a[i] += k-1;
	printf("%d\n",a[0]/k+a[1]/k+a[2]/k);
	return 0;
}
