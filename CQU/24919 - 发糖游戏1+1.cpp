#include <bits/stdc++.h>
using namespace std;
inline int lowbit(int x) {
	return x & (-x);
}
namespace sweet1{
	int n;
	long long a[100005];
	inline void insert(int x,int d) {
		for (int i=x;i<=n;i+=lowbit(i)) a[i] += d;
	}
	inline long long sum(int x) {
		long long ret = 0;
		for (int i=x;i>=1;i-=lowbit(i)) {
			ret += a[i];
		}
		return ret;
	}
	inline long long query(int l,int r) {
		return sum(r)-sum(l-1);
	}
	void run(int _n) {
		n = _n;
		memset(a,0,sizeof(a));
		int q;
		scanf("%d",&q);
		while (q--) {
			int o;
			scanf("%d",&o);
			if (o == 0) {
				int a,b;
				scanf("%d%d",&a,&b);
				insert(a,b);
			}
			else {
				int a,b;
				scanf("%d%d",&a,&b);
				printf("%lld\n",query(a,b));
			}
		}
	}
};
namespace sweet2{
	int n;
	long long a[100005];
	inline void add(int x,int d) {
		for (int i=x;i<=n;i+=lowbit(i)) a[i] += d;
	}
	inline void insert(int l,int r,int d) {
		add(l,d);
		add(r+1,-d);
	}
	inline long long query(int x) {
		long long ret = 0;
		for (int i=x;i>=1;i-=lowbit(i)) {
			ret += a[i];
		}
		return ret;
	}
	void run(int _n) {
		n = _n;
		memset(a,0,sizeof(a));
		int q;
		scanf("%d",&q);
		while (q--) {
			int o;
			scanf("%d",&o);
			if (o == 0) {
				int a,b,c;
				scanf("%d%d%d",&a,&b,&c);
				insert(a,b,c);
			}
			else {
				int a;
				scanf("%d",&a);
				printf("%lld\n",query(a));
			}
		}
	}
}
char buf[105];
int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		int n;
		scanf("%d",&n);
		scanf("%s",buf);
		scanf("%s",buf);
		sweet1::run(n);
		scanf("%s",buf);
		scanf("%s",buf);
		sweet2::run(n);
	}
	return 0;
}
