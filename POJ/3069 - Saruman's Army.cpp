#include <cstdio>
#include <algorithm>
using namespace std;
int pos[1005];
int main() {
	int r,n;
	while (scanf("%d%d",&r,&n) == 2) {
		if (n == -1) break;
		for (int i=0;i<n;i++) scanf("%d",&pos[i]);
		pos[n] = 0x7fffffff;
		sort(pos,pos+n);
		int i = 0;
		int ans = 0;
		while (i != n) {
			ans ++;
			int mid = i;
			while (pos[mid+1] <= pos[i] + r) mid ++;
			int j = mid;
			while (pos[j] <= pos[mid] + r) j ++;
			i = j;
		}
		printf("%d\n",ans);
	}
	return 0;
}
