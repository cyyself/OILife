#include <bits/stdc++.h>
using namespace std;
long long f[25][25][2005];
int num[25];
long long dfs(long long dep,long long mid,long long sum,bool uplimited) {
	if (sum < 0) return 0;
	if (dep == -1) {
		return (sum == 0);
	}
	else {
		if (!uplimited && f[dep][mid][sum] != -1) return f[dep][mid][sum];
		long long up = 9;
		if (uplimited) up = num[dep];
		long long ans = 0;
		for (long long i=0;i<=up;i++) {
			ans += dfs(dep-1,mid,sum+i*(dep-mid),uplimited && i == up);
		}
		if (!uplimited) f[dep][mid][sum] = ans;
		return ans;
	}
}
long long solve(long long x) {
	int len = 0;
	while (x) {
		num[len++] = x % 10;
		x /= 10;
	}
	long long ans = 0;
	for (int mid=0;mid<len;mid++) {
		ans += dfs(len-1,mid,0,true);
	}
	ans -= len - 1;
	return ans;
}
int main() {
	memset(f,-1,sizeof(f));
	int T;
	scanf("%d",&T);
	while (T --) {
		long long x,y;
		cin >> x >> y;
		cout << solve(y) - solve(x-1) << endl;
	}
	return 0;
}
