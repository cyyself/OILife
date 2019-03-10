#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
int a[100];
long long f[100][100];
int main() {
	memset(f,0x3f,sizeof(f));
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n-1;i++) f[i][i] = a[i-1]*a[i]*a[i+1];
	for (int len=2;len<=n;len++) {
		for (int i=1;i+len-1<n-1;i++) {
			int j = i + len - 1;
			for (int mid=i;mid<=j;mid++) {
				long long cur = a[mid] * a[i-1] * a[j+1];
				if (f[i][mid-1] < INF) cur += f[i][mid-1];
				if (f[mid+1][j] < INF) cur += f[mid+1][j];
				f[i][j] = min(f[i][j],cur);
			}
		}
	}
	printf("%lld\n",f[1][n-2]);
	return 0;
}
