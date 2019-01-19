#include <bits/stdc++.h>
using namespace std;
struct DATA {
	int a,b;
	int seq;
}arr[100005];
bool cmp(const DATA &a,const DATA &b) {
	if (a.b == b.b) return a.a < b.a;
	return a.b > b.b;
}
bool cmp2(const DATA &a,const DATA &b) {
	if (a.a == b.a) return a.b > b.b;
	return a.a > b.a;
}
int main() {
	int n,p,k;
	scanf("%d%d%d",&n,&p,&k);
	for (int i=0;i<n;i++) {
		scanf("%d%d",&arr[i].a,&arr[i].b);
		arr[i].seq = i + 1;
	}
	sort(arr,arr+n,cmp);
	sort(arr,arr+(n - (p - k)),cmp2);
	set <int> ans;
	int m = 0x3f3f3f3f;
	for (int i=0;i<k;i++) {
		ans.insert(arr[i].seq);
		m = min(m,arr[i].b);
	}
	sort(arr+k,arr+n,cmp);
	for (int i=k;i<n && ans.size() < p;i++) {
		if (arr[i].b < m || i > n - (p-k) - 1) ans.insert(arr[i].seq);
	}
	for (auto x:ans) printf("%d ",x);
	puts("");
	return 0;
}
