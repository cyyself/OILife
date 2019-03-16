#include <bits/stdc++.h>
using namespace std;
int t[4];
vector <int> p[4];
char s[2][5005];
int main() {
	int n;
	scanf("%d",&n);
	scanf("%s%s",s[0],s[1]);
	for (int i=0;i<n;i++) {
		t[(s[0][i]-'0')+(s[1][i]-'0')*2] ++;
		p[(s[0][i]-'0')+(s[1][i]-'0')*2].push_back(i+1);
	}
	for (int c1=0;c1<=t[1];c1++) {
		for (int c2=0;c2<=t[2];c2++) {
			if (c1 + c2 > t[2]+t[3]) break;
			if ((t[2]+t[3]-c1-c2) % 2 != 0) continue;
			int c3 = (t[2]+t[3]-c1-c2) / 2;
			if (c3 > t[3] || c3 < 0) continue;
			int c0 = n/2 - c1 - c2 - c3;
			if (c0 > t[0] || c0 < 0) continue;
			//OK
			while (c0--) printf("%d ",p[0][c0]);
			while (c1--) printf("%d ",p[1][c1]);
			while (c2--) printf("%d ",p[2][c2]);
			while (c3--) printf("%d ",p[3][c3]);
			printf("\n");
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}
