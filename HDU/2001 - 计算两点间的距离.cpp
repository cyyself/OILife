#include <bits/stdc++.h>
int main() {
	double x,y,xx,yy;
	while (scanf("%lf%lf%lf%lf",&x,&y,&xx,&yy) == 4) {
		printf("%0.2lf\n",sqrt( (x-xx)*(x-xx) + (y-yy)*(y-yy) ));
	}
	return 0;
}