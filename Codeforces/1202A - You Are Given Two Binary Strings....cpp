#include <bits/stdc++.h>
using namespace std;
char a[100005],b[100005];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		scanf("%s%s",a,b);
		int lena = strlen(a), lenb = strlen(b);
		reverse(a,a+lena);
		reverse(b,b+lenb);
		int posb = 0;
		while (b[posb] != '1') posb ++;
		int posa = posb;
		while (a[posa] != '1') posa ++;
		printf("%d\n",posa-posb);
	}
	return 0;
}
