#include <bits/stdc++.h>
using namespace std;
char s[15];
bool ask(int x) {
	printf("%d 1\n",x);
	fflush(stdout);
	scanf("%s",s);
	return s[0] == 'b';
}
int main() {
	int n;
	scanf("%d",&n);
	int l = 0;
	int r = 1e9;
	bool first = ask(0);
	while (--n) {
		int mid = (l + r) / 2;
		if (ask(mid) == first) l = mid;
		else r = mid;
	}
	printf("%d 0 %d 2\n",l,l+1);
	fflush(stdout);
	return 0;
}
