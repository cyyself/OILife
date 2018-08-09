#include <bits/stdc++.h>
using namespace std;
char a[100005];
char b[100005];
int main() {
	int n;
	scanf("%d",&n);
	scanf("%s%s",a,b);
	long long cnt_0 = 0;
	long long cnt_1 = 0;
	long long replace_0 = 0;
	long long replace_1 = 0;
	for (int i=0;i<n;i++) {
		if (a[i] == '0') cnt_0 ++;
		if (a[i] == '1') cnt_1 ++;
		if (a[i] == '0' && b[i] == '0') replace_1 ++;
		if (a[i] == '1' && b[i] == '0') replace_0 ++;
	}
	cout << replace_1 * cnt_1 + replace_0 * (cnt_0 - replace_1) << endl;
	return 0;
}
