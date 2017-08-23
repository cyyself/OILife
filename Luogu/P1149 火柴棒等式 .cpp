/*
#include <cstdio>
int n;
const int number[10]={6,2,5,5,4,5,6,3,7,6};
int calc(int x) {
	if (x == 0) return number[0];
	int ret = 0;
	while(x != 0) {
		int t = x % 10;
		ret += number[t];
		x /= 10;
	}
	return ret;
}
int work(int n) {
	int ans = 0;
	for (int i=0;i<=1000;i++) 
		for (int j=0;j<=1000;j++)
			if (calc(i) + calc(j) + calc(i+j) + 4 == n) ans++;
	return ans;
}
int main() {
	printf("const int ans[25]={0");
	for (int i=1;i<=24;i++) {
		printf(",%d",work(i));
	}
	printf("}\n");
	return 0;
}
*/

#include <cstdio>
int main() {
	int n;
	const int ans[25]={0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,8,9,6,9,29,39,38,65,88,128};
	scanf("%d",&n);
	printf("%d\n",ans[n]);
	return 0;
}