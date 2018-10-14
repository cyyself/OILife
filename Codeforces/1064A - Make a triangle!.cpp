#include <bits/stdc++.h>
using namespace std;
int a[3];
int main() {
	for (int i=0;i<3;i++) cin >> a[i];
	sort(a,a+3);
	int need = a[2] - a[1] - a[0] + 1;
	if (need < 0) need = 0;
	cout << need << endl;
	return 0;
}
