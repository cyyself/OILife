#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	scanf("%d",&n);
	int len = sqrt(n);
	int cur = n - len + 1;
	do {
		for (int i=0;i<len;i++) printf("%d ",cur+i);
		cur -= len;
	}
	while (cur > 0);
	cur += len;
	for (int i=1;i<cur;i++) printf("%d ",i);
	printf("\n");
	return 0;
}
