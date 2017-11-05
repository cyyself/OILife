#include <bits/stdc++.h>
using namespace std;
int n;
struct specialnum {
	//用于upper_bound，因为lower_bound可以等于，而我们第一个问题要求小于，所以重载一下运算符改变符号，配合upper_bound变成一个不能等于的lower_bound
	int x;
	friend bool operator < (const specialnum &a,const specialnum &b) {
		return a.x > b.x;
	}
	specialnum(){

	}
	specialnum(int _x) {
		x = _x;
	}
}f[100005];
int a[100005];
int g[100005];
int main() {
	int tmp;
	while (scanf("%d",&a[++n]) == 1);
	n --;
	f[1] = specialnum(a[1]);
	g[1] = a[1];
	int ans1 = 1;
	int ans2 = 1;
	for (int i=2;i<=n;i++) {
		int p = upper_bound(f+1,f+ans1+1,specialnum(a[i])) - f;
		f[p] = specialnum(a[i]);
		ans1 = max(ans1,p);
		int q = lower_bound(g+1,g+ans2+1,a[i]) - g;
		g[q] = a[i];
		ans2 = max(ans2,q);
	}
	printf("%d\n%d\n",ans1,ans2);
	return 0;
}
