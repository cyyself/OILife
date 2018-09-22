#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	scanf("%d",&n);
	int a = 1,b = 1;
	int c = n - 2;
	if (c % 3 == 0) {
		c --;
		b ++;
	}
	printf("%d %d %d\n",a,b,c);
	return 0;
}
