#include <bits/stdc++.h>
using namespace std;
int main() {
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int sum1 = a * 2 + c;
	int sum2 = c + d * 2;
	if (sum1 == sum2 && (c == 0 || (a != 0 && d != 0))) {
		printf("1\n");
	}
	else printf("0\n");
	return 0;
}
