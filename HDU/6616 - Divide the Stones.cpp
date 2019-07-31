#include <bits/stdc++.h>
using namespace std;
long long n,k;
void snakefill(int start,int end,vector<int> (&ans)[100000]) {
	int d = 1;
	int pos = 1;
	for (int i=start;i<=end;i++) {
		ans[pos].push_back(i);
		pos += d;
		if (pos > k || pos <= 0) {
			pos -= d;
			d = -d;
		}
	}
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		scanf("%lld%lld",&n,&k);
		long long sum = (n * (n + 1)) /2;
		int start = 1;
		if (sum % k == 0) {
			printf("yes\n");
			vector <int> ans[100000];
			if ((n / k) & 1) {
				if (k == 1) for (int i=1;i<=n;i++) ans[1].push_back(i);
				else {
					for (int i=1;i<=k;i++) ans[i].push_back(i);
					int pos = k;
					for (int i=k+1;i<=2*k;i++) {
						ans[pos].push_back(i);
						pos -= 2;
						if (pos <= 0) pos = k - 1;
					}
					for (int i=1;i<=k;i++) ans[i].push_back((3*k)*(3*k+1)/2/k - ans[i][0] - ans[i][1]);
					start = 3 * k + 1;
					snakefill(start,n,ans);
				}
			}
			else snakefill(start,n,ans);
			for (int i=1;i<=k;i++) {
				for (int j=0;j<ans[i].size();j++) {
					if (j) printf(" ");
					printf("%d",ans[i][j]);
				}
				printf("\n");
			}
		}
		else printf("no\n");
	}
	return 0;
}
