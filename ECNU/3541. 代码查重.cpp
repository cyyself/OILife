#include <bits/stdc++.h>
using namespace std;

map <pair<int,int>,bool> exist;


int xmm[100005];
int ult[100005];

int main() {
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	if (n != m) {
		printf("No\n");
		return 0;
	}
	for (int i=0;i<n;i++) scanf("%d",&xmm[i]);
	for (int i=0;i<m;i++) scanf("%d",&ult[i]);
	for (int i=0;i<k;i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		if (x > y) swap(x,y);
		if (!exist[make_pair(x,y)]) {
			exist[make_pair(x,y)] = true;
		}
	}
	for (int i=0;i<m;i++) {
		int a = xmm[i];
		int b = ult[i];
		if (a > b) swap(a,b);
		if (!(a == b || exist[make_pair(a,b)]) ) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}
