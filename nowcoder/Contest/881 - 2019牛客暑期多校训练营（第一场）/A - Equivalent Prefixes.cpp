#include <bits/stdc++.h>
using namespace std;
int L[2][100005],R[2][100005];
int a[100005],b[100005];
int n;
void work_R(int *arr,int *r) {
	stack <int> s;
	for (int i=1;i<=n;i++) {
		while (!s.empty()) {
			if (arr[s.top()] > arr[i]) {
				r[s.top()] = i - 1;
				s.pop();
			}
			else break;
		}
		s.push(i);
	}
	while (!s.empty()) {
		r[s.top()] = n;
		s.pop();
	}
}
void work_L(int *arr,int *l) {
	stack <int> s;
	for (int i=n;i>=1;i--) {
		while (!s.empty()) {
			if (arr[s.top()] > arr[i]) {
				l[s.top()] = i + 1;
				s.pop();
			}
			else break;
		}
		s.push(i);
	}
	while (!s.empty()) {
		l[s.top()] = 1;
		s.pop();
	}
}
int main() {
	while (scanf("%d",&n) == 1) {
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=n;i++) scanf("%d",&b[i]);
		work_R(a,R[0]);
		work_R(b,R[1]);
		work_L(a,L[0]);
		work_L(b,L[1]);
		int ans = n;
		for (int i=1;i<=n;i++) {
			if (L[0][i] != L[1][i]) ans = min(ans,i-1);
			if (R[0][i] != R[1][i]) ans = min(ans,min(R[0][i],R[1][i]));
		}
		printf("%d\n",ans);
	}
	return 0;
}
