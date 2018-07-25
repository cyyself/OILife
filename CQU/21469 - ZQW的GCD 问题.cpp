#include <bits/stdc++.h>
char tmp[100005];
int phrase() {
	int len = strlen(tmp);
	int ret = 0;
	for (int i=0;i<len;i++) 
		if (tmp[i] >= '0' && tmp[i] <= '9')
			ret += tmp[i] - '0';
	return ret;
}
int gcd(int a,int b) {
	if (b == 0) return a;
	return gcd(b,a%b);
}
int main() {
	int t;
	scanf("%d",&t);
	while (t--) {
		scanf("%s",tmp);
		int a = phrase();
		scanf("%s",tmp);
		int b = phrase();
		printf("%d\n",gcd(a,b));
	}
	return 0;
}
