#include <cstdio>
int searchx(int n) {
	int ans = 0;
	while(++ans && (ans*(ans+1))/2 < n);
	return ans;
}
int main() {
	int n;
	scanf("%d",&n);
	int x = searchx(n);
	if (x % 2) {
		int m = n - (x*(x-1))/2;
		int z = x + 1 - m;
		printf("%d/%d\n",z,m);
	}
	else {
		int z = n - (x*(x-1))/2;
		int m = x + 1 - z;
		printf("%d/%d\n",z,m);
	}
	return 0;
}