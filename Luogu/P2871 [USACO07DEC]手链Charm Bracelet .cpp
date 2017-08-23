#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	int Wi[3407];
	int Di[3407];
	for (int i=0;i<n;i++) scanf("%d%d",&Wi[i],&Di[i]);
	int f[12885] = {0};
	for (int i=0;i<n;i++) 
		for (int j=m;j>=0;j--) {
			f[j] = max(f[j],f[j-Wi[i]]+Di[i]);
		}
	printf("%d\n",f[m]);
	return 0;
}