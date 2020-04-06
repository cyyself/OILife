#include <bits/stdc++.h>
using namespace std;
struct DATA {
	pair <int,int> i;
	int id;
	friend bool operator < (const DATA &a,const DATA &b) {
		return a.i < b.i;
	}
};
DATA a[1005];
int ans[1005];
int main() {
	int T;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++) {
		int n;
		scanf("%d",&n);
		for (int i=0;i<n;i++) {
			scanf("%d%d",&a[i].i.first,&a[i].i.second);
			a[i].id = i;
		}
		sort(a,a+n);
		bool ok = true;
		int free[2] = {0,0};
		for (int i=0;i<n && ok;i++) {
			if (a[i].i.first >= free[0]) {
				ans[a[i].id] = 0;
				free[0] = a[i].i.second;
			}
			else if (a[i].i.first >= free[1]) {
				ans[a[i].id] = 1;
				free[1] = a[i].i.second;
			}
			else ok = false;
		}
		printf("Case #%d: ",cas);
		if (!ok) printf("IMPOSSIBLE\n");
		else {
			for (int i=0;i<n;i++) printf("%c",ans[i]?'J':'C');
			printf("\n");
		}
	}
	return 0;
}
