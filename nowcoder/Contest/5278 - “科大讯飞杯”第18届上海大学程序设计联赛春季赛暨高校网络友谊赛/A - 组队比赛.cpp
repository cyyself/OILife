#include <bits/stdc++.h>
using namespace std;
int main() {
	int a[4];
	scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]);
	int p[4] = {0,1,2,3};
	int ans = 0x3f3f3f3f;
	do {
		int team1 = a[p[0]] + a[p[1]];
		int team2 = a[p[2]] + a[p[3]];
		ans = min(ans,abs(team1-team2));
	}
	while (next_permutation(p,p+4));
	printf("%d\n",ans);
	return 0;
}
