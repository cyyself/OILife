#include <bits/stdc++.h>
using namespace std;
int n;
int arr[50005];
inline int lowbit(int x) {
	return x & (-x);
}
inline void add(int pos,int d) {
	for (int i=pos;i<=n;i+=lowbit(i)) arr[i] += d;
}
inline long long sum(int pos) {
	long long sum = 0;
	for (int i=pos;i>=1;i-=lowbit(i)) sum += arr[i];
	return sum;
}
int main() {
	int T;
	scanf("%d",&T);
	for (int c=1;c<=T;c++) {
		memset(arr,0,sizeof(arr));
		scanf("%d",&n);
		for (int i=1;i<=n;i++) {
			int t;
			scanf("%d",&t);
			add(i,t);
		}
		printf("Case %d:\n",c);
		string cmd;
		while (cin >> cmd) {
			if (cmd == "End") break;
			int x,y;
			cin >> x >> y;
			if (cmd == "Query") printf("%lld\n",sum(y)-sum(x-1));
			else if (cmd == "Add") add(x,y);
			else if (cmd == "Sub") add(x,-y);
		}
	}
	return 0;
}
