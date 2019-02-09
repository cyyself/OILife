#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n,s;
		scanf("%d%d",&n,&s);
		int sum = 0;
		int ans = n+1;
		queue <int> q;
		for (int i=0;i<n;i++) {
			int x;
			scanf("%d",&x);
			q.push(x);
			sum += x;
			while (sum >= s) {
				ans = min(ans,(int)q.size());
				sum -= q.front();
				q.pop();
			}
		}
		if (ans > n) printf("0\n");
		else printf("%d\n",ans);
	}
	return 0;
}
