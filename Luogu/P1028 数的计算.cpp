#include <cstdio>
int DFS(int x) {
	int ans = 0;
	int mid = x >> 1;
	ans += mid;
	for (int i=1;i<=mid;i++) ans += DFS(i);
	return ans;
}
int main() {
	int n;
	scanf("%d",&n);
	printf("%d\n",DFS(n)+1);
	return 0;
}