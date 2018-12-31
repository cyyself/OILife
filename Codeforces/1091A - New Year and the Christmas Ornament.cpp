#include <bits/stdc++.h>
using namespace std;
int main() {
	int y,b,r;
	scanf("%d%d%d",&y,&b,&r);
	int MIN = min(y,min(b-1,r-2));
	printf("%d\n",MIN*3+3);
	return 0;
}
