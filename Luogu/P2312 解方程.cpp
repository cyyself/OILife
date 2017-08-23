#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
int n;
long long read() {
	long long ret = 0;
	long long f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		ret = ret * 10 + c - '0';
		ret %= 1000000007;
		c = getchar();
	}
	return ret * f;
}
bool judge(long long x) {
	long long sum = 0;
	for (int i=n;i>=0;i--) {
		sum = sum * x + a[i];
		sum %= 1000000007;
	}
	return sum == 0;
}
vector <int> ans;
int main() {
	int m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<=n;i++) a[i] = read();
	for (int i=1;i<=m;i++) if (judge(i)) ans.push_back(i);
	printf("%lu\n",ans.size());
	for (int i=0;i<ans.size();i++) printf("%d\n",ans[i]);
	return 0;
}