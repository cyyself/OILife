#include <bits/stdc++.h>
using namespace std;
int a[105];
int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	int min_num = 0x7fffffff;
	int min_pos = -1;
	int max_num = 0x80000000;
	int max_pos = -1;
	for (int i=0;i<n;i++) if (a[i] <= min_num) {
		min_num = a[i];
		min_pos = i;
	}
	for (int i=n-1;i>=0;i--) if (a[i] >= max_num) {
		max_num = a[i];
		max_pos = i;
	}
	int dis = n - 1 - min_pos + max_pos;
	if (min_pos < max_pos) dis --;
	printf("%d\n",dis);
	return 0;
}
