#include <cstdio>
int a0,a1,b0,b1;
int gcd(int a,int b) {
	if (b == 0) return a;
	else return gcd(b,a%b);
}
bool judge(int x) {
	if (x % a1 == 0) return (gcd(x/a1,a0/a1)==1&&gcd(b1/b0,b1/x)==1);
	else return false; 
}
int main() {
	int n;
	scanf("%d",&n);
	while (n--) {
		scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
		int cnt = 0;
		for (int x=1;x*x<=b1;x++) {
			if (b1 % x == 0) {
				cnt += judge(x);
				if (x*x != b1) cnt += judge(b1/x);
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}