#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int L[1000005][3];
int R[1000005][3];
string s1,s2;
struct DATA {
	int l,r;
	friend bool operator < (const DATA &a,const DATA &b) {
		return a.r - a.l > b.r - b.l;
	}
};
int main() {
	scanf("%s",s+1);
	int len = strlen(s+1);
	L[len+1][0] = L[len+1][1] = L[len+1][2] = len + 1;
	R[0][0] = R[0][1] = R[0][2] = 0;
	for (int i=len;i>=1;i--) {
		for (int j=0;j<3;j++) {
			if (s[i]-'a' == j) L[i][j] = i;
			else L[i][j] = L[i+1][j];
		}
	}
	for (int i=1;i<=len;i++) {
		for (int j=0;j<3;j++) {
			if (s[i]-'a' == j) R[i][j] = i;
			else R[i][j] = R[i-1][j];
		}
	}
	int l = 1;
	int r = len;
	while (l <= r) {
		DATA tmp[3] = {
			{L[l][0],R[r][0]},
			{L[l][1],R[r][1]},
			{L[l][2],R[r][2]},
		};
		sort(tmp,tmp+3);
		if (tmp[0].r-tmp[0].l > 0) {
			s1.push_back(s[tmp[0].l]);
			s2.push_back(s[tmp[0].r]);
		}
		else if (tmp[0].r == tmp[0].l) {
			s1.push_back(s[tmp[0].l]);
			break;
		}
		else break;
		l = tmp[0].l + 1;
		r = tmp[0].r - 1;
	}
	reverse(s2.begin(),s2.end());
	if (s1.length() + s2.length() < len / 2) cout << "IMPOSSIBLE" << endl;
	else cout << s1 << s2 << endl;
	return 0;
}
