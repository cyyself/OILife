#include <bits/stdc++.h>
using namespace std;
int a[100005];
struct DATA {
	int v,w;
};
int main() {
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int ans = 0;
	stack <DATA> s;
	for (int i=1;i<=n;i++) {
		int tmp = 0;
		while (!s.empty() && s.top().v < a[i]) {
			tmp = max(tmp,s.top().w);
			s.pop();
		}
		s.push((DATA){a[i],s.empty()?0:tmp+1});
		ans = max(ans,s.top().w);
	}
	printf("%d\n",ans);
	return 0;
}
