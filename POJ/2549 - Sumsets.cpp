#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
int a[1000];
pair<int,pair<int,int> > b[1000000];
int main() {
	int n;
	while (scanf("%d",&n) == 1 && n) {
		for (int i=0;i<n;i++) scanf("%d",&a[i]);
		sort(a,a+n);
		reverse(a,a+n);
		int bcnt = 0;
		for (int i=0;i<n;i++) for (int j=i+1;j<n;j++) b[bcnt++] = make_pair(a[i] + a[j],make_pair(i,j));
		sort(b,b+bcnt);
		int ans = 0x80000000;
		for (int i=0;i<n && ans == 0x80000000;i++) for (int j=0;j<n;j++) {
			if (i == j) continue;
			int sum = a[i] - a[j];
			pair<int,pair<int,int> >* ptr = upper_bound(b,b+bcnt,make_pair(sum,make_pair(j+1,0)));
			if (ptr->first == sum) {
				if (ptr->second.first != i && ptr->second.second != i) {
					ans = a[i];
					break;
				}
			}
		}
		if (ans == 0x80000000) printf("no solution\n");
		else printf("%d\n",ans);
	}
	return 0;
}
