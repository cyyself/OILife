#include <cstdio>
int m;
int len;
int a[25];
bool used[25];
bool ok;
void dfs(int seq,int sum,int skip) {
	if (seq == 3) ok = true;
	else {
		for (int i=skip;i<m && !ok;i++) {
			if (used[i]) continue;
			if (sum + a[i] < len) {
				used[i] = true;
				dfs(seq,sum+a[i],i+1);
				used[i] = false;
			}
			if (sum + a[i] == len) {
				used[i] = true;
				dfs(seq+1,0,0);
				used[i] = false;
			}
		}
	}
}
int main() {
	int n;
	scanf("%d",&n);
	while (n--) {
		ok = false;
		scanf("%d",&m);
		int tot = 0;
		for (int i=0;i<m;i++) {
			scanf("%d",&a[i]);
			used[i] = false;
			tot += a[i];
		}
		if (tot % 4 != 0) {
			printf("no\n");
			continue;
		}
		len = tot / 4;
		dfs(0,0,0);
		if (ok) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
