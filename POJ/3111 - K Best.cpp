#include <cstdio>
#include <algorithm>
#include <set>
#include <utility>
using namespace std;
struct DATA {
	int v,w;
	double val;
	int pos;
	friend bool operator < (const DATA &a,const DATA &b) {
		return a.val > b.val;
	}
	void reset(double x) {
		val = v - x * w;
	}
}a[100005];
int n,k;
void reset_all(double x) {
	for (int i=0;i<n;i++) a[i].reset(x);
}
bool check(double x) {
	reset_all(x);
	sort(a,a+n);
	double sum = 0;
	for (int i=0;i<k;i++) sum += a[i].val;
	return sum >= 0;
}
int ans[100005];
int main() {
	scanf("%d%d",&n,&k);
	double l = 0,r = 1e9;
	for (int i=0;i<n;i++) {
		scanf("%d%d",&a[i].v,&a[i].w);
		a[i].pos = i + 1;
	}
	while (r - l > 1e-8) {
		double mid = (l + r) / 2;
		if (check(mid)) {
			l = mid;
			/*
			之前WA了半天，
			把

			for (int i=0;i<k;i++) ans[i] = a[i].pos;

			放在这里
			然而这样的话，当最大值为0时，就没法输出答案了
			*/
		}
		else r = mid;
	}
	for (int i=0;i<k;i++) ans[i] = a[i].pos;
	sort(ans,ans+k);
	for (int i=0;i<k;i++) {
		if (i != 0) printf(" ");
		printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
}
