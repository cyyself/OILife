#include <bits/stdc++.h>
using namespace std;
pair <int,int> x[1005];
pair <int,int> a[1005];
int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d%d",&x[i].first,&x[i].second);
	for (int i=0;i<n;i++) scanf("%d%d",&a[i].first,&a[i].second);
	sort(x,x+n);
	sort(a,a+n);
	int tx = 0;
	int ty = 0;
	tx = x[0].first + a[n-1].first;
	ty = x[0].second + a[n-1].second;
	printf("%d %d\n",tx,ty);
	return 0;
}
