#include <bits/stdc++.h>
using namespace std;
long long a[400005];
int n;
int lowbit(int x) {
	return x & (-x);
}

void add(int x,long long d) {
	for (int i=x;i<=n;i+=lowbit(i)) a[i] += d;
}
long long sum(int x) {
	long long ret = 0;
	for (int i=x;i>=1;i-=lowbit(i)) ret += a[i];
	return ret;
}
long long query(int l,int r) {
	return sum(r) - sum(l-1);
}
long long mem[400005];
long long f[400005];//f[j]表示在j之后(含j)可行解的最大值
long long p[400005];//p[j]表示在j之后(含j)可行解的位置
int main() {
	int k;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) {
		long long tmp;
		cin >> tmp;
		add(i,tmp);
	}
	for (int i=1;i+k-1<=n;i++) mem[i] = query(i,i+k-1);
	p[n-k+1] = n - k + 1;
	f[n-k+1] = mem[n-k+1];
	for (int i=n-k;i>=1;i--) {
		if (mem[i] > f[i+1]) {
			f[i] = mem[i];
			p[i] = i;
		}
		else if (mem[i] == f[i+1]) {
			f[i] = mem[i];
			p[i] = i;
		}
		else {
			f[i] = f[i+1];
			p[i] = p[i+1];
		}
	}
	long long ans = 0x8000000000000000;
	int ans_a = -1;
	int ans_b = -1;
	for (int i=1;i<=n-(k*2)+1;i++) {
		if (mem[i] + f[i+k] > ans) {
			ans = mem[i] + f[i+k];
			ans_a = i;
			ans_b = p[i+k];
		}
	}
	printf("%d %d\n",ans_a,ans_b);
	return 0;
}
