#include <cstdio>
#include <algorithm>
using namespace std;
int f[40005];
int Pi[105];
int Wi[105];
int Ni[105];
int main() {
	int n,w;
	scanf("%d%d",&n,&w);
	for (int i=0;i<n;i++) scanf("%d%d%d",&Pi[i],&Wi[i],&Ni[i]);
	for (int i=0;i<n;i++) {
		for (int k=1;k<=Ni[i];k*=2) {
			Ni[i] -= k;
			for (int j=w;j>=k*Wi[i];j--) {
				f[j] = max(f[j],f[j-k*Wi[i]]+Pi[i]*k);
			}
		}
		for (int j=w;j>=Ni[i]*Wi[i];j--) {
			f[j] = max(f[j],f[j-Wi[i]*Ni[i]]+Pi[i]*Ni[i]);
		}
	}
	printf("%d\n",f[w]);
	return 0;
}