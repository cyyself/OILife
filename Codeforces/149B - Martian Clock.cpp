#include <bits/stdc++.h>
using namespace std;
long long getnum(char c) {
	if (c >= '0' && c <= '9') return c - '0';
	else return 10 + c - 'A';
}
bool judge(string a,long long system) {
	long long xs = 1;//系数
	long long time[2] = {0};//1是分钟，0是小时
	int cur = 1;//当前是分钟还是小时
	for (int i=a.length()-1;i>=0;i--) {
		if (a[i] == ':') {
			xs = 1;
			cur = 0;
			continue;
		}
		int num = getnum(a[i]);
		if (num >= system) return false;
		time[cur] += xs * getnum(a[i]);
		xs *= system;
	}
	return (time[1] < 60 && time[0] < 24);
}
int main() {
	string time;
	cin >> time;
	if (judge(time,61)) {
		printf("-1\n");
	}
	else {
		bool first = true;
		for (int i=2;i<=60;i++) {
			if (judge(time,i)) {
				if (!first) printf(" ");
				printf("%d",i);
				first = false;
			}
		}
		if (first) printf("0");
		printf("\n");
	}
	return 0;
}
