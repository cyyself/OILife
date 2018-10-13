#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
int d[15];
int dp;
char s[105];
int main() {
	int T;
	scanf("%d",&T);
	cin.getline(s,105);
	while (T --) {
		dp = 0;
		int ans = INF;
		cin.getline(s,105);
		for (int i=0;s[i];i++) if (s[i] >= '0' && s[i] <= '9') d[dp++] = s[i] - '0';
		int per[15];
		for (int i=0;i<dp;i++) per[i] = i;
		do {
			int mid = dp / 2;
			int a = 0;
			int b = 0;
			for (int p=0;p<mid;p++) {
				a *= 10;
				a += d[per[p]];
			}
			for (int p=mid;p<dp;p++) {
				b *= 10;
				b += d[per[p]];
			}
			if (mid >= 2 && d[per[0]] == 0) continue;
			if (dp - mid >= 2 && d[per[mid]] == 0) continue;
			ans = min(ans,abs(a-b));
		}
		while (next_permutation(per,per+dp));
		printf("%d\n",ans);
	}
	return 0;
}
