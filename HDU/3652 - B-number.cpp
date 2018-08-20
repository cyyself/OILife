#include <bits/stdc++.h>
using namespace std;
int f[10][13][2][2];
int num[10];
int dfs(int dep,int mod,bool exist1,bool ok,bool uplimited) {
	if (dep == -1) {
		return (ok && mod == 0);
	}
	else {
		if (!uplimited && f[dep][mod][exist1][ok] != -1) return f[dep][mod][exist1][ok];
		int up = 9;
		if (uplimited) up = num[dep];
		int res = 0;
		for (int i=0;i<=up;i++) {
			res += dfs(dep-1,(10*mod+i)%13,i == 1,ok || (exist1 && i == 3),uplimited && i == up);
		}
		if (!uplimited) f[dep][mod][exist1][ok] = res;
		return res;
	}
}
int solve(int x) {
	int len = 0;
	while (x) {
		num[len++] = x % 10;
		x /= 10;
	}
	return dfs(len-1,0,false,false,true);
}
int main() {
	memset(f,-1,sizeof(f));
	int n;
	while (scanf("%d",&n) == 1) printf("%d\n",solve(n));
	return 0;
}
