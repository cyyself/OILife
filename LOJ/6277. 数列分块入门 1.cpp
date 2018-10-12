#include <bits/stdc++.h>
using namespace std;
int a[50000];
int b[224];//这个块所有元素加上的值
int main() {
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int bsize = sqrt(n);
	for (int i=0;i<n;i++) {
		int o,l,r,c;
		scanf("%d%d%d%d",&o,&l,&r,&c);
		if (o == 0) {
			for (int j=l;j<=r;j++) {
				if (j % bsize == 1 && j + bsize - 1 <= r) {
					//修改一个块
					b[(j-1)/bsize] += c;
					j += bsize - 1;//因为之后还会j ++，所以要-1
				}
				else a[j] += c;
			}
		}
		else {
			printf("%d\n",a[r] + b[(r-1)/bsize]);
		}
	}
	return 0;
}
