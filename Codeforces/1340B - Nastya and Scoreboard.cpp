#include <bits/stdc++.h>
using namespace std;
int f[2005][2005][10];
int genbin(string x) {
	int res = 0;
	for (int i=0;i<x.length();i++) 
		if (x[i] == '1') res |= 1 << i;
	return res;
}
string nums[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int num[10];
int exist[2005];
int n;
int dfs(int cur,int rem,int sel) {
	if (f[cur][rem][sel] != -1) return f[cur][rem][sel];
	if (cur == n) {
		return f[cur][rem][sel] = (rem == 0);
	}
	else {
		bool ok = false;
		for (int i=9;i>=0;i--) if ((num[i] | exist[cur+1]) == num[i]) {
			int extra = num[i] ^ exist[cur+1];
			if (rem-__builtin_popcount(extra) < 0) continue;
			ok |= dfs(cur+1,rem-__builtin_popcount(extra),i);
		}
		return f[cur][rem][sel] = ok;
	}
}
int ans[2005];
void dfs2(int cur,int rem,int sel) {
	if (cur == n) {
		return;
	}
	else {
		for (int i=9;i>=0;i--) if ((num[i] | exist[cur+1]) == num[i]) {
			int extra = num[i] ^ exist[cur+1];
			if (rem-__builtin_popcount(extra) < 0) continue;
			if (f[cur+1][rem-__builtin_popcount(extra)][i] == 1) {
				ans[cur+1] = i;
				dfs2(cur+1,rem-__builtin_popcount(extra),i);
				return;
			}
		}
	}
}
int main() {
	for (int i=0;i<10;i++) num[i] = genbin(nums[i]);
	memset(f,-1,sizeof(f));
	int k;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) {
		string t;
		cin >> t;
		exist[i] = genbin(t);
	}
	dfs(0,k,0);
	if (f[0][k][0] == 1) {
		dfs2(0,k,0);
		for (int i=1;i<=n;i++) printf("%d",ans[i]);
		printf("\n");
	}
	else printf("-1\n");
	return 0;
}
