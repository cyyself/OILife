#include <bits/stdc++.h>
using namespace std;
map <long long,bool> exist;
long long f[11];
void DFS(int dep,long long cur) {
	if (cur) exist[cur] = true;
	if (dep >= 0) {
		DFS(dep-1,cur+f[dep]);
		DFS(dep-1,cur);
	}
}
int main() {
	f[0] = 1;
	f[1] = 1;
	for (int i=2;i<=10;i++) f[i] = f[i-1] * i;
	DFS(10,0);
	long long n;
	while (scanf("%lld",&n) == 1) {
		if (n < 0) break;
		if (exist[n]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
