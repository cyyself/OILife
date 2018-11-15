#include <cstdio>
#include <cstring>
bool f[100005];
int a[105];
int c[105];
int main() {
	int n,m;
	while (scanf("%d%d",&n,&m) == 2 && n) {
		memset(f,false,sizeof(f));
		f[0] = true;
		for (int i=0;i<n;i++) scanf("%d",&a[i]);
		for (int i=0;i<n;i++) scanf("%d",&c[i]);
		for (int i=0;i<n;i++) {
			for (int k=1;k<=c[i];k<<=1) {
				c[i] -= k;
				for (int j=m;j>=a[i]*k;j--) f[j] |= f[j-a[i]*k];
			}
			for (int j=m;j>=a[i]*c[i];j--) f[j] |= f[j-a[i]*c[i]];
		}
		int ans = 0;
		for (int i=1;i<=m;i++) ans += f[i];
		printf("%d\n",ans);
	}
	return 0;
}
