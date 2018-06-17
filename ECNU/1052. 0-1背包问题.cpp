#include <bits/stdc++.h>
using namespace std;
int f[100005];
int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		memset(f,0,sizeof(f));
		int n,M;
		scanf("%d%d",&n,&M);
		while (n--) {
			int w,p;
			scanf("%d%d",&w,&p);
			for (int i=M;i>=w;i--) f[i] = max(f[i],f[i-w]+p);
		}
		printf("%d\n",f[M]);
	}
	return 0;
}
