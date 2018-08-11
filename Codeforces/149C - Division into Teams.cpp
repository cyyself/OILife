#include <bits/stdc++.h>
using namespace std;
struct DATA {
	int v;
	int pos;
	friend bool operator < (const DATA &a,const DATA &b) {
		return a.v < b.v;
	}
}d[100005];
int main() {
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d",&d[i].v);
		d[i].pos = i;
	}
	sort(d+1,d+1+n);
	printf("%d\n",(n/2) + (n&1));
	for (int i=1;i<=n;i+=2) {
		if (i != 1) printf(" ");
		printf("%d",d[i].pos);
	}
	printf("\n");
	printf("%d\n",n/2);
	for (int i=2;i<=n;i+=2) {
		if (i != 2) printf(" ");
		printf("%d",d[i].pos);
	}
	return 0;
}
