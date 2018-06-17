#include <bits/stdc++.h>
bool judge(int year) {
	if (year % 4 == 0) {
		if (year % 400 == 0) return true;
		if (year % 100 == 0) return false;
		return true;
	}
	return false;
}
int main() {
	int y;
	scanf("%d",&y);
	int t = 0;
	int r = 0;
	int cnt = 0;
	for (int i=2001;i<=y;i++) {
		t += 7*20;
		if (judge(i)) {
			r += 100 * 7;
			cnt ++;
		}
	}
	printf("%d %d %d\n",cnt,t,r);
	return 0;
}
