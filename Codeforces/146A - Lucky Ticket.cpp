#include <bits/stdc++.h>
using namespace std;
char s[55];
int main() {
	int n;
	scanf("%d%s",&n,s);
	bool lucky = true;
	for (int i=0;i<n;i++) if (s[i] != '7' && s[i] != '4') {
		lucky = false;
		break;
	}
	if (lucky) {
		int suml = 0;
		for (int i=0;i<n/2;i++) {
			suml += s[i] - '0';
		}
		int sumr = 0;
		for (int i=n/2;i<n;i++) {
			sumr += s[i] - '0';
		}
		if (suml != sumr) lucky = false;
	}
	if (lucky) printf("YES\n");
	else printf("NO\n");
	return 0;
}
