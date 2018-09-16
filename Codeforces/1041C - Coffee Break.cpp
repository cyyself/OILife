#include <bits/stdc++.h>
using namespace std;
struct num {
	int val;
	int index;
	friend bool operator < (const num &a,const num &b) {
		return a.val < b.val;
	}
}arr[200005];
struct DATA {
	int time;
	int day;
	friend bool operator < (const DATA &a,const DATA &b) {
		return a.time > b.time;
	}
};
int ans[200005];
int main() {
	int n,m,d;
	scanf("%d%d%d",&n,&m,&d);
	for (int i=0;i<n;i++) {
		scanf("%d",&arr[i].val);
		arr[i].index = i;
	}
	sort(arr,arr+n);
	priority_queue <DATA> q;
	int dayneed = 1;

	q.push((DATA){arr[0].val,1});
	ans[arr[0].index] = 1;

	for (int i=1;i<n;i++) {
		DATA cur = q.top();
		if (cur.time + d + 1 > arr[i].val) {
			//要用新的一天
			q.push((DATA){arr[i].val,++dayneed});
			ans[arr[i].index] = dayneed;
		}
		else {
			q.pop();
			q.push((DATA){arr[i].val,cur.day});
			ans[arr[i].index] = cur.day;
		}
	}
	printf("%d\n",dayneed);
	for (int i=0;i<n;i++) {
		if (i != 0) printf(" ");
		printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
}
