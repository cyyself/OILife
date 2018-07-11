#include <bits/stdc++.h>
using namespace std;
long long a[300005];
long long n,k;
long long getans(long long mid) {
	long long ret = 0;
	for (int i=0;i<n;i++) ret += abs(a[i]-mid);
	return ret;
}
long long max(long long a,long long b) {
	if (a > b) return a;
	return b;
}
long long min(long long a,long long b) {
	if (a < b) return a;
	return b;
}
int main() {
	cin >> n >> k;
	for (long long i=0;i<n;i++) {
		cin >> a[i];
		a[i] -= k * i;
	}
	sort(a,a+n);
	//三角不等式，把所有都变换为中位数时操作数最少
	//若中位数小于0，则直接选择0
	if (n % 2) cout << getans(max(0,a[n/2])) << endl;//不能出现负数
	else {
		long long ans_1 = getans(max(0,a[n/2]));
		long long ans_2 = getans(max(0,a[n/2-1]));
		cout << min(ans_1,ans_2) << endl;
	}
	return 0;
}