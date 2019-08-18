#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long pre[500005];
long long f[500005];
class mydeque: public deque<int> {
public:
	int front_second() {
		int f1 = front();
		pop_front();
		int f2 = front();
		push_front(f1);
		return f2;
	}
	int back_second() {
		int b1 = back();
		pop_back();
		int b2 = back();
		push_back(b1);
		return b2;
	}
};
inline long long getfz(int j,int k) {
	return f[j] + pre[j] * pre[j] - f[k] - pre[k] * pre[k];
}
inline long long getfm(int j,int k) {
	return 2LL * (pre[j] - pre[k]);
}
bool judge(int i,int j,int k) {
	return getfz(j,k) <= pre[i] * getfm(j,k);
}
bool judge2(int i,int j,int k) {
	return getfz(i,j) * getfm(j,k) >= getfz(j,k) * getfm(i,j);
}
int main() {
	int n,m;
	while (scanf("%d%d",&n,&m) == 2) {
		mydeque q;
		for (int i=1;i<=n;i++) {
			scanf("%lld",&a[i]);
			pre[i] = pre[i-1] + a[i];
		}
		q.push_back(0);
		for (int i=1;i<=n;i++) {
			while (q.size() >= 2 && judge(i,q.front_second(),q.front())) q.pop_front();
			f[i] = f[q.front()] + (pre[i] - pre[q.front()]) * (pre[i] - pre[q.front()]) + m;
			while (q.size() >= 2 && judge2(i,q.back_second(),q.back())) q.pop_back();
			q.push_back(i);
		}
		printf("%lld\n",f[n]);
	}
	return 0;
}
