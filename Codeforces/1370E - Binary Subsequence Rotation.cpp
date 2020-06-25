#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
char a[maxn],b[maxn];
int main() {
	int n;
	scanf("%d",&n);
	scanf("%s%s",a,b);
	int dep = 0;
	int l = 0,r = 0;
	for (int i=0;i<n;i++) {
		if (a[i] != b[i]) {
			if (a[i] == '0') dep --;
			else dep ++;
		}
		l = min(l,dep);
		r = max(r,dep);
	}
	if (dep != 0) printf("-1\n");
	else printf("%d\n",r-l);
	return 0;
}
