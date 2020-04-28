#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int cal(long long x,long long y) {
	x = abs(x);
	y = abs(y);
	if ((x + y) & 1 || x + y == 0) {
		for (int i=0;i<=32;i++) {
			if ((1ll << i) - 1 >= x + y) return i;
		}
	}
	else return inf;
}
int main() {
	int T;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++) {
		long long x,y;
		scanf("%lld%lld",&x,&y);
		if ((x + y) & 1) {
			int d = cal(x,y);
			vector <char> ans;
			for (int i=d-1;i>=0;i--) {
				long long d = 1ll << i;
				if (cal(x-d,y) <= i) {
					ans.push_back('E');
					x -= d;
				}
				else if (cal(x+d,y) <= i) {
					ans.push_back('W');
					x += d;
				}
				else if (cal(x,y-d) <= i) {
					ans.push_back('N');
					y -= d;
				}
				else if (cal(x,y+d) <= i) {
					ans.push_back('S');
					y += d;
				}
				else assert(false);
			}
			assert(abs(x) + abs(y) == 0);
			reverse(ans.begin(),ans.end());
			printf("Case #%d: ",cas);
			for (auto x:ans) printf("%c",x);
			printf("\n");
		}
		else printf("Case #%d: IMPOSSIBLE\n",cas);
	}
	return 0;
}
