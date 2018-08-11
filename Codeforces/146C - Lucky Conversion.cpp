#include <bits/stdc++.h>
using namespace std;
char a[100005];
char b[100005];
int main() {
	scanf("%s%s",a,b);
	int len = strlen(a);
	int rep_4 = 0;
	int rep_7 = 0;
	for (int i=0;i<len;i++) if (a[i] != b[i]) {
		if (a[i] == '7') rep_7 ++;
		else rep_4 ++;
	}
	int swap_cnt = min(rep_4,rep_7);
	rep_4 -= swap_cnt;
	rep_7 -= swap_cnt;
	printf("%d\n",swap_cnt + rep_4 + rep_7);
	return 0;
}
