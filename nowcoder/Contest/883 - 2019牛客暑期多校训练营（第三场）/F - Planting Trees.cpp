#include <bits/stdc++.h>
using namespace std;
struct mydeque {
	int arr[1005];
	int head,tail;
	void init() {
		head = 500;
		tail = 499;
	}
	int front() {
		return arr[head];
	}
	int back() {
		return arr[tail];
	}
	void push_front(int x) {
		arr[--head] = x;
	}
	void push_back(int x) {
		arr[++tail] = x;
	}
	void pop_front() {
		head ++;
	}
	void pop_back() {
		tail --;
	}
	bool empty() {
		return tail < head;
	}
};
int a[505][505];
int MIN[505],MAX[505];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n,m;
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) scanf("%d",&a[i][j]);
		int ans = 1;
		for (int l=1;l<=n;l++) {
			memset(MAX,0,sizeof(int) * (n+1));
			memset(MIN,0x3f,sizeof(int) * (n + 1));
			for (int r=l;r<=n;r++) {
				for (int i=1;i<=n;i++) {
					MIN[i] = min(MIN[i],a[r][i]);
					MAX[i] = max(MAX[i],a[r][i]);
				}
				mydeque q1,q2;
				q1.init();
				q2.init();
				int p = 1;
				for (int i=1;i<=n;i++) {
					while (!q1.empty()) {
						if (MIN[q1.back()] >= MIN[i]) q1.pop_back();
						else break;
					}
					q1.push_back(i);
					while (!q2.empty()) {
						if (MAX[q2.back()] <= MAX[i]) q2.pop_back();
						else break;
					}
					q2.push_back(i);
					while (!q1.empty() && !q2.empty() && MAX[q2.front()] - MIN[q1.front()] > m) {
						if (q2.front() < q1.front()) {
							p = q2.front() + 1;
							q2.pop_front();
						}
						else {
							p = q1.front() + 1;
							q1.pop_front();
						}
					}
					if (!q1.empty() && !q2.empty()) {
						int len = i - p + 1;
						ans = max(ans,len*(r-l+1));
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}