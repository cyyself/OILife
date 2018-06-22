#include <bits/stdc++.h>
using namespace std;
bool comp(const int &a,const int &b) {
	if (abs(a) > abs(b)) return true;
	if (abs(a) == abs(b) && a < b) return true;
	return false;
}
int a[25];
int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n,comp);
	printf("%d",a[0]);
	for (int i=1;i<n;i++) printf(",%d",a[i]);
	return 0;
}