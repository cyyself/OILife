#include <bits/stdc++.h>
using namespace std;
int fibo[1005];
int sg[1005];
bool s[1005];
int main() {
	fibo[0] = 1;
	fibo[1] = 1;
	for (int i=2;i<=50;i++) fibo[i] = fibo[i-1] + fibo[i-2];
	for (int i=0;i<=1000;i++) {
		for (int j=0;j<=1000;j++) s[j] = false;
		for (int j=1;fibo[j]<=i;j++) s[sg[i-fibo[j]]] = true;
		for (int j=0;j<=1000;j++) if (!s[j]) {
			sg[i] = j;
			break;
		}
	}
	int m,n,p;
	while (scanf("%d%d%d",&m,&n,&p) == 3 && m && n && p) {
		if (sg[m] ^ sg[n] ^ sg[p]) printf("Fibo\n");
		else printf("Nacci\n");
	}
	return 0;
}
