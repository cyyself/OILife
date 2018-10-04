/*
0.56787878...
=0.56 + 0.01X
=0.56 + 0.078/99
=2811/4950
*/
#include <cstdio>
#include <cstring>
long long gcd(long long a,long long b) {
	if (b == 0) return a;
	else return gcd(b,a%b);
}
void sim(long long &a,long long &b) {
	long long g = gcd(a,b);
	a /= g;
	b /= g;
}
char s[15];
int main() {
	while (scanf("%s",s) && s[1] != '\0') {
		int len = 2;
		while (s[len] != '.') len ++;
		long long ans_fz;
		long long ans_fm = 0x7fffffffffffffff;
		for (int mid=2;mid<len;mid++) {
			//非循环节与循环节的分界线
			long long pre_fz = 0;//非循环节的分子
			long long pre_fm = 1;
			for (int i=2;i<mid;i++) {
				pre_fz *= 10;
				pre_fz += s[i] - '0';
				pre_fm *= 10;
			}
			long long suf_fz = 0;
			long long suf_fm = 1;
			for (int i=mid;i<len;i++) {
				suf_fz *= 10;
				suf_fz += s[i] - '0';
				suf_fm *= 10;
			}
			if (suf_fm != 1) suf_fm --;
			long long fz = pre_fz * suf_fm + suf_fz;
			long long fm = pre_fm * suf_fm;
			sim(fz,fm);
			if (fm < ans_fm) {
				ans_fz = fz;
				ans_fm = fm;
			}
		}
		printf("%lld/%lld\n",ans_fz,ans_fm);
	}
	return 0;
}
