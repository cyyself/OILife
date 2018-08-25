#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
long long n;
void dfs(int dep,long long num) {
	if (num > n) return;
	cnt ++;
	dfs(dep+1,10*num+4);
	dfs(dep+1,10*num+7);
}
int main() {
	cin >> n;
	dfs(0,4);
	dfs(0,7);
	cout << cnt << endl;
	return 0;
}
