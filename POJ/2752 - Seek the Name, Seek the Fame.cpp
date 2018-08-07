#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
char s[400005];
int nxt[400005];
int len;
void getnext() {
	nxt[0] = -1;
	int k = -1;
	for (int i=1;i<len;i++) {
		while (k != -1 && s[i] != s[k+1]) k = nxt[k];
		if (s[i] == s[k+1]) k ++;
		nxt[i] = k;
	}
}
vector <int> ans;
int main() {
	while (scanf("%s",s) == 1) {
		ans.clear();
		len = strlen(s);
		getnext();
		int t = nxt[len-1];
		while (t != -1) {
			if (s[t] == s[len-1]) ans.push_back(t+1);
			t = nxt[t];
		}
		reverse(ans.begin(),ans.end());
		ans.push_back(len);
		for (int i=0;i<ans.size();i++) {
			if (i != 0) printf(" ");
			printf("%d",ans[i]);
		}
		printf("\n");
	}
	return 0;
}
