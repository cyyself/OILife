#include <cstdio>
#include <algorithm>
using namespace std;
int f[355][355];
int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) 
		for (int j=0;j<=i;j++) scanf("%d",&f[i][j]);
	for (int i=n-2;i>=0;i--) {
		for (int j=0;j<=i;j++) f[i][j] += max(f[i+1][j],f[i+1][j+1]);
	}
	printf("%d\n",f[0][0]);
	return 0;
}
