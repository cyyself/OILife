#include <bits/stdc++.h>
int main() {
	long long a,b,c,x_1,x_2,y_1,y_2;
	while (scanf("%lld%lld%lld%lld%lld%lld%lld",&a,&b,&c,&x_1,&x_2,&y_1,&y_2) == 7) {
		long long cnt = 0;
		for (long long i=x_1;i<=x_2;i++)
			for (long long j=y_1;j<=y_2;j++) if (a*i + b*j + c == 0) cnt ++;
		printf("%lld\n",cnt);
	}
	return 0;
}
