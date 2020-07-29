#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
char a[maxn],b[maxn];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n;
		scanf("%d%s%s",&n,a,b);
		int ans = 0;
		map <char,set<char> > mem;
		for (int i=0;i<n;i++) {
			if (a[i] > b[i]) {
				ans = -1;
				break;
			}
			else if (a[i] < b[i]) mem[a[i]].insert(b[i]);
		}
		if (ans != -1) {
			for (char c='a';c<='z';c++) {
				if (mem[c].size()) {
					if (mem[c].size() != 1) {
						char MI = *mem[c].begin();
						for (auto x:mem[c]) if (x != MI) mem[MI].insert(x);
					}
					ans ++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
