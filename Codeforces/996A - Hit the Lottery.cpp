#include <bits/stdc++.h>
int deno[5] = {100,20,10,5,1};
int main() {
	int n;
	scanf("%d",&n);
	int ans = 0;
	for (int i=0;i<5;i++) {
		ans += n / deno[i];
		n %= deno[i];
	}
	printf("%d\n",ans);
	return 0;
}