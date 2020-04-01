#include <bits/stdc++.h>
using namespace std;
int getbit(int n,int p) {
	return (n & (1 << p)) >> p;
}
int main() {
	int n;
	scanf("%d",&n);
	int a[6];
	for (int i=0;i<6;i++) a[i] = getbit(n,i);
	swap(a[0],a[4]);
	swap(a[2],a[3]);
	int x = 0;
	for (int i=0;i<6;i++) x |= a[i] << i;
	printf("%d\n",x);
	return 0;
}
