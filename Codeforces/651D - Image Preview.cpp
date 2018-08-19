#include <bits/stdc++.h>
using namespace std;
char s[500005];
int sum[500005];
int n,a,b,t;
bool judge(int page) {
	for (int left=1;left<=page;left++) {//左边滑的页数
		int right = page - left;//右边滑的页数
		int sumt = sum[left] + (sum[n] - sum[n-right]);
		int st1 = (left-1) * a * 2 + right * a;//先向右滑动，再向左滑动
		int st2 = right * a * 2 + (left - 1) * a;//先向左滑动，再向右滑动
		if (sumt + min(st1,st2) <= t) return true;
	}
	return false;
}
int main() {
	scanf("%d%d%d%d",&n,&a,&b,&t);
	scanf("%s",&s[1]);
	for (int i=1;i<=n;i++) {
		sum[i] = sum[i-1] + 1;
		if (s[i] == 'w') sum[i] += b;
	}
	int l = 0;
	int r = n;
	while (l < r) {
		int mid = (l + r + 1) / 2;
		if (judge(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d\n",l);
	return 0;
}
