#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int d[maxn];
int len[maxn];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&d[i]);
		for (int i=1;i<=n+1;i++) len[i] = max(1,max(d[i-1],d[i]));
		string last = "";
		for (int i=1;i<=len[1];i++) last += 'a';
		cout << last << endl;
		for (int i=2;i<=n+1;i++) {
			string cur = "";
			for (int j=1;j<=len[i];j++) {
				if (j <= d[i-1]) cur += last[j-1];
				else {
					if (j <= len[i-1]) cur += last[j-1]=='a'?'b':'a';
					else cur += 'a';
				}
			}
			cout << cur << endl;
			last = cur;
		}
	}
	return 0;
}
