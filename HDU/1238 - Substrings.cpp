#include <bits/stdc++.h>
using namespace std;
char s[105][105];
char p[105];
int nxt[105];
bool kmp(char *str,int x) {
	int k = -1;
	for (int i=0;str[i] != 0;i++) {
		while (k != -1 && str[i] != p[k+1]) k = nxt[k];
		if (str[i] == p[k+1]) k++;
		if (k == x - 1) return true;
	}
	return false;
}
void getnext() {
	nxt[0] = -1;
	int k = -1;
	for (int i=1;p[i] != 0;i++) {
		while (k != -1 && p[i] != p[k+1]) k = nxt[k];
		if (p[i] == p[k+1]) k++;
		nxt[i] = k;
	}
}
int n;
bool check(int x) {
	if (x == 0) return true;
	int len = strlen(&s[0][0]);
	for (int i=0;i<len-x+1;i++) {
		//枚举子串
		for (int j=0;j<x;j++) p[j] = s[0][i+j];
		p[x] = 0;
		getnext();
		bool flag = true;
		for (int j=1;j<n;j++) {
			if (!kmp(&s[j][0],x)) {
				int jlen = strlen(&s[j][0]);
				reverse(&s[j][0],&s[j][jlen]);
				if (!kmp(&s[j][0],x)) {
					flag = false;
					break;
				}
			}
		}
		if (flag) return true;
	}
	return false;
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		scanf("%d",&n);
		int minl = 0x3f3f3f3f;
		int minp = 0;
		for (int i=0;i<n;i++) {
			scanf("%s",&s[i][0]);
			int len = strlen(&s[i][0]);
			if (len < minl) {
				minl = len;
				minp = i;
			}
		}
		for (int i=0;i<=minl;i++) swap(s[0][i],s[minp][i]);
		int l = 0;
		int r = minl;
		int ans = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid)) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
