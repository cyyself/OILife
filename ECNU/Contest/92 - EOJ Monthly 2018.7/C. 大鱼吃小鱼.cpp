#include <bits/stdc++.h>
using namespace std;
struct fish{
	long long w;
	long long a;
	fish() {

	}
	fish(long long _w,long long _a) {
		w = _w;
		a = _a;
	}
	friend bool operator < (const fish &a,const fish &b) {
		if (a.a * b.a <= 0) return a.a > b.a;
		else {
			if (a.a > 0) return a.w < b.w;
			else return a.a+a.w > b.a+b.w;
		}
	}
}f[1000005];
int n;
int main() {
	cin >> n;
	for (int i=0;i<n;i++) {
		long long w,a;
		cin >> w >> a;
		f[i] = fish(w,a);
	}
	sort(f,f+n);
	long long ans = -1;
	long long tmp = 0;
	for (int i=0;i<n;i++) {
		ans = min(ans,min(tmp-f[i].w,tmp+f[i].a-1));
		// 这次需要的大小（可以使tmp==0） 需要保持大小为正整数所需要的大小
		tmp += f[i].a;
	}
	cout << -ans << endl;
	return 0;
}