#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	scanf("%d",&n);
	int cur = 1;
	while (n > 3) {
		int range = n - (n/2);
		for (int i=0;i<range;i++) printf("%d ",cur);
		n = n - range;
		cur <<= 1;
	}
	switch (n) {
		case 3:
			printf("%d %d %d",cur,cur,cur*3);
			break;
		case 2:
			printf("%d %d",cur,cur*2);
			break;
		case 1:
			printf("%d",cur);
			break;
	}
	printf("\n");
	return 0;
}
