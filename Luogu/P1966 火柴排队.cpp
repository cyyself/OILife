#include <bits/stdc++.h>
using namespace std;
const int mo = 99999997;
struct num {
	int x;
	int pos;
	friend bool operator < (const num &a,const num &b) {
		if (a.x < b.x) return true;
		else return false;
	}
}a[100005],b[100005];
int tr[100005];//树状数组
int q[100005];
int n;
inline int lowbit(int x) {
	return x&(-x);
}
inline int sum(int x) {
	int ret = 0;
	for (int i=x;i>=1;i-=lowbit(i)) {
		ret += tr[i];
		ret %= mo;
	}
	return ret;
}
inline void add(int x,int d) {
	for (int i=x;i<=n;i+=lowbit(i)) {
		tr[i] += d;
		tr[i] %= mo;
	}
}
int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i].x);
		a[i].pos = i;
	}
	for (int i=1;i<=n;i++) {
		scanf("%d",&b[i].x);
		b[i].pos = i;
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	for (int i=1;i<=n;i++) {
		q[a[i].pos] = b[i].pos;
		//printf("q[%d] = %d;\n",a[i].pos,b[i].pos);
	}
	int ans = 0;
	for (int i=n;i>=1;i--) {
		ans += sum(q[i]-1);
		add(q[i],1);
		ans %= mo;
	}
	printf("%d\n",ans);
	return 0;
}
