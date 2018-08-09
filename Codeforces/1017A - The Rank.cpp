#include <bits/stdc++.h>
using namespace std;
struct stu {
	int id;
	int sum;
	friend bool operator < (const stu &a,const stu &b) {
		if (a.sum > b.sum) return true;
		if (a.sum == b.sum && a.id < b.id) return true;
		return false;
	}
}s[1005];
int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		s[i].id = i + 1;
		for (int j=0;j<4;j++) {
			int t;
			scanf("%d",&t);
			s[i].sum += t;
		}
	}
	sort(s,s+n);
	int ans = -1;
	for (int i=0;i<n;i++) {
		if (s[i].id == 1) {
			ans = i;
			break;
		}
	}
	printf("%d\n",ans+1);
	return 0;
}
