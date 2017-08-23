#include <cstdio>
#include <queue>
using namespace std;
struct comp{
	bool operator() (int x,int y) {
		return x > y;
	}
};
priority_queue<int,vector<int>,comp>q;
int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int t;
		scanf("%d",&t);
		q.push(t);
	}
	int ans = 0;
	while(q.size() != 1) {
		int a = q.top();
		q.pop();
		int b = q.top();
		q.pop();
		int t = a + b;
		ans += t;
		q.push(t);
	}
	printf("%d\n",ans);
	return 0;
}