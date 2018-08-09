#include <bits/stdc++.h>
using namespace std;
map <int,int> zys;//first是质因数，second是count
map <int,int> cnt;//m的每个质因数当前使用的次数
void fjzys(int x) {
	zys.clear();
	int up = sqrt(x) + 0.5;
	for (int i=2;i<=up;i++) {
		while (x % i == 0) {
			zys[i] ++;
			x /= i;
		}
	}
	if (x > 1) zys[x] ++;
}
bool check(int n,int m) {
	int fz = n + 1 - m;
	if (m == 0) fz = 1;
	int fm = max(m,1);
	for (auto each:zys) {
		while (fz % each.first == 0) {
			fz /= each.first;
			cnt[each.first] ++;
		}
		while (fm % each.first == 0) {
			fm /= each.first;
			cnt[each.first] --;
		}
	}
	for (auto each:zys) if (cnt[each.first] < each.second) return false;
	return true;
}
int main() {
	int n,m;
	while (scanf("%d%d",&n,&m) == 2) {
		fjzys(m);
		cnt.clear();
		vector <int> ans;
		for (int i=0;i<=n-1;i++) {//实际上是求C(n-1,0:n-1)中多少个数能被m整除
			if (check(n-1,i)) ans.push_back(i+1);
		}
		printf("%lu\n",ans.size());
		bool first = true;
		for (auto each:ans) {
			if (!first) printf(" ");
			printf("%d",each);
			first = false;
		}
		printf("\n");
	}
	return 0;
}
