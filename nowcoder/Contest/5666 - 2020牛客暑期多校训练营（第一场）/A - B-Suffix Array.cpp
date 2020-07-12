#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
unsigned long long preh[2][maxn];//prefix hash
unsigned long long base[maxn];
char s[maxn];
int pre[maxn][2];
int ans[maxn];
int n;
inline int hash_equal(int a,int b,int l) {
	return (s[a] ^ s[b]) ? (preh[1][a+l-1] - preh[1][a-1])*base[b-a] == preh[0][b+l-1] - preh[0][b-1]
	:(preh[0][a+l-1] - preh[0][a-1])*base[b-a] == preh[0][b+l-1] - preh[0][b-1];
}
inline bool cmp(int a,int b) {
	int rev1 = 0;
	if (a > b) {
		swap(a,b);
		rev1 = 1;
	}
	int lena = n - a + 1;
	int lenb = n - b + 1;
	int l = 1, r = min(lena,lenb);
	int len = 0;//equal len
	int mid;//若不预先定义mid会导致TLE，调了4个小时。
	while (l <= r) {
		mid = (l + r) >> 1;
		if (hash_equal(a,b,mid)) {
			len = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	if (len == min(lena,lenb)) {
		return (lena < lenb) ^ rev1;
	}
	int diffa = a + len - pre[a+len][s[a+len]];
	if (diffa > len) diffa = 0;
	int diffb = b + len - pre[b+len][s[b+len]];
	if (diffb > len) diffb = 0;
	return (diffa < diffb) ^ rev1;
}
int main() {
	base[0] = 1;
	for (int i=1;i<maxn;i++) base[i] = base[i-1] * 3;
	while (scanf("%d",&n) == 1) {
		scanf("%s",s+1);
		int p[2] = {0,0};
		for (int i=1;i<=n;i++) {
			s[i] -= 'a';
            pre[i][0] = p[0];
            pre[i][1] = p[1];
            p[s[i]] = i;
			preh[0][i] = preh[0][i-1] + (1+s[i]) * base[i];
			preh[1][i] = preh[1][i-1] + (2-s[i]) * base[i];
		}
		for (int i=1;i<=n;i++) ans[i] = i;
		sort(ans+1,ans+1+n,cmp);
		for (int i=1;i<=n;i++) printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}
