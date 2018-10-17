#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
struct DATA {
	int num;
	friend bool operator < (const DATA &a,const DATA &b) {
		return a.num > b.num;
	}
	DATA(int _num) {
		num = _num;
	}
};
priority_queue <DATA> q;
int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int t;
		scanf("%d",&t);
		q.push(t);
	}
	long long ans = 0;
	while (q.size() >= 2) {//当q.size() == 1时，说明全部拼起来了
		int tmp = 0;
		DATA cur = q.top();
		tmp += cur.num;
		q.pop();
		cur = q.top();
		tmp += cur.num;
		q.pop();
		q.push(DATA(tmp));
		ans += tmp;
	}
	printf("%lld\n",ans);
	return 0;
}
