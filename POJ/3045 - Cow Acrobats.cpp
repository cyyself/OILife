#include <cstdio>
#include <algorithm>
using namespace std;
struct DATA {
	int w,s;
	friend bool operator < (const DATA &a,const DATA &b) {
		return a.w + a.s < b.w + b.s;
	}
}arr[50005];
int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d%d",&arr[i].w,&arr[i].s);
	sort(arr,arr+n);
	int pre = 0;
	int ans = 0x80000000;
	for (int i=0;i<n;i++) {
		ans = max(ans,pre-arr[i].s);
		pre += arr[i].w;
	}
	printf("%d\n",ans);
	return 0;
}
