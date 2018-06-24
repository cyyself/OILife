#include <bits/stdc++.h>
using namespace std;
bool check(int x) {
	if (x % 36 != 0) return false;
	char s[10];
	memset(s,0,sizeof(s));
	sprintf(s+1,"%d",x);
	int len = strlen(s+1);
	bool exist = false;
	for (int i=1;i<=len;i++) {
		if (s[i] == '3' && s[i+1] == '6') exist = true;
		if (s[i] == '3' && s[i+1] != '6') return false;
		if (s[i] == '6' && s[i-1] != '3') return false;
	}
	return exist;
}
vector <int> m;
int main() {
	for (int i=1;i<=100000;i++) if (check(i)) m.push_back(i);
	int T;
	scanf("%d",&T);
	while (T--) {
		int l;
		scanf("%d",&l);
		vector<int>::iterator p = lower_bound(m.begin(),m.end(),l);
		if (*p == 0) printf("-1\n");
		else printf("%d\n",*p);
	}
	return 0;
}
