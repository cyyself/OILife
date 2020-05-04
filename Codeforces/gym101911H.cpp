#include <bits/stdc++.h>
using namespace std;
int main() {
	long long n,m;
	scanf("%lld%lld",&n,&m);
	long long px1,py1,px2,py2;
	scanf("%lld%lld%lld%lld",&px1,&py1,&px2,&py2);
	long long l = py1 - 1;
	long long r = m - py2;
	long long need1 = (l & 1) + (r & 1);
	long long need2 = m & 1;
	long long all = (need1*(px2-px1+1)+need2*(n-(px2-px1+1)) + 1) / 2;
	printf("%lld\n",all);
	return 0;
}
