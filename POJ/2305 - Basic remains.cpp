#include <cstdio>
#include <algorithm>
int b;
long long read(char* c,long long m) {
	long long ret = 0;
	while (*c >= '0' && *c <= '9') {
		ret *= b;
		ret %= m;
		ret += *c - '0';
		ret %= m;
		c ++;
	}
	return ret;
}
long long read(char* c) {
	long long ret = 0;
	while (*c >= '0' && *c <= '9') {
		ret *= b;
		ret += *c - '0';
		c ++;
	}
	return ret;
}
char str_p[1005];
char str_m[1005];
char out[1005];
int main() {
	while (scanf("%d",&b) == 1 && b) {
		scanf("%s%s",str_p,str_m);
		long long m = read(str_m,1e9);
		if (m == 0) {
			printf("0\n");
			continue;
		}
		long long k = read(str_p,m);
		int cnt = 0;
		while (k) {
			out[cnt++] = '0' + k % b;
			k /= b;
		}
		if (cnt == 0) out[cnt++] = '0';
		std::reverse(out,out+cnt);
		out[cnt] = 0;
		printf("%s\n",out);
	}
	return 0;
}
