#include <bits/stdc++.h>
using namespace std;
const long long mo = 1000000007;
const long long arr[20] = {5702887,583861472,544858368,671547416,959748993,877938922,565260452,896391145,980885286,306348017,492511528,365706550,843601769,784821368,812613589,252939603,221023796,747596614,945538639,491355305};
const long long arr2[8] = {1,1,1,2,5,21,233,10946};
long long read() {
	long long ret = 0;
	char c = getchar();
	while (!(c >= '0' && c <= '9')) c = getchar();
	while (c >= '0' && c <= '9') {
		ret *= 10;
		ret %= mo;
		ret += c - '0';
		ret %= mo;
		c = getchar();
	}
	return ret;
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		long long n = read();
		bool flag = false;
		for (int i=0;i<(1<<20) && !flag;i++) {
			long long sum = 0;
			for (int j=0;j<20;j++) if (i & (1 << j)) sum = (sum + arr[j]) % mo;

			if ((n - sum + mo) % mo <= 11210) {
				long long d = (n - sum + mo) % mo;
				for (int j=(sum==0?1:0);j<(1<<8) && !flag;j++) {
					long long sum2 = 0;
					for (int k=0;k<8;k++) if (j & (1 << k)) sum2 += arr2[k];
					if (sum2 == d) {
						for (int l=0;l<8;l++) {
							if (j & (1 << l)) {
								if (flag) printf(" ");
								printf("%d",l+1);
								flag = true;
							}
						}
						for (int l=0;l<20;l++) {
							if (i & (1 << l)) {
								if (flag) printf(" ");
								printf("%d",l+9);
								flag = true;
							}
						}
						printf("\n");
					}
				}
			}
		}
		if (!flag) printf("-1\n");
	}
	return 0;
}
