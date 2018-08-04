#include <bits/stdc++.h>
using namespace std;
int main() {
	int x,y;
	scanf("%d%d",&x,&y);
	int sum = abs(x) + abs(y);
	if (x < 0) {
		if (y < 0) printf("%d %d %d %d\n",-sum,0,0,-sum);
		else printf("%d %d %d %d\n",-sum,0,0,sum);
	}
	else {
		if (y < 0) printf("%d %d %d %d\n",0,-sum,sum,0);
		else printf("%d %d %d %d\n",0,sum,sum,0);
	}
	return 0;
}
