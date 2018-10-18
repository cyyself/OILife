#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int ans[100005];
int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&arr[i]);
	int cur = arr[n-1];
	for (int i=n-2;i>=0;i--) {
		ans[i] = max(0,cur+1-arr[i]);
		cur = max(cur,arr[i]);
	}
	for (int i=0;i<n;i++) {
		if (i != 0) printf(" ");
		printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
}
