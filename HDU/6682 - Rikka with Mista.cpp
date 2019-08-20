#include <bits/stdc++.h>
using namespace std;
int a[1<<20],b[1<<20];
int w[40];
int cnt1,cnt2;
int n;
void init() {
	cnt1 = (n + 1) / 2;
	cnt2 = n / 2;
	for (int s=0;s<(1<<cnt1);s++) {
		a[s] = 0;
		for (int j=0;j<cnt1;j++) if ((s >> j) & 1) a[s] += w[j];
	}
	for (int s=0;s<(1<<cnt2);s++) {
		b[s] = 0;
		for (int j=0;j<cnt2;j++) if ((s >> j) & 1) b[s] += w[cnt1+j];
	}
}
int mod;
bool cmp(int a,int b) {
	return (a % 10) < (b % 10);
}

void merge_sort(int *arr,int size,int base) {
	static int tmp[10][1<<20];
	static int cnt[10];
	memset(cnt,0,sizeof(cnt));
	for (int i=0;i<size;i++) {
		int pos = (arr[i] / base) % 10;
		tmp[pos][cnt[pos]++] = arr[i];
	}
	int ptr = 0;
	for (int i=0;i<10;i++) {
		for (int j=0;j<cnt[i];j++) arr[ptr++] = tmp[i][j];
	}
}
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%d",&w[i]);
		init();
		sort(a,a+(1<<cnt1),cmp);
		sort(b,b+(1<<cnt2),cmp);
		long long ans = 0;
		int cur = 1;
		for (int base=0;base<=8;base++) {
			mod = cur * 10;
			if (base != 0) {
				merge_sort(a,1<<cnt1,cur);
				merge_sort(b,1<<cnt2,cur);
			}
			int mid = 0;//b里面进位的位置
			while (a[0] % mod + b[mid] % mod < 10 * cur && mid < (1<<cnt2)) mid ++;
			int l1 = 0, r1 = mid - 1;
			int l2 = mid, r2 = (1 << cnt2) - 1;
			while ((a[0] + b[l1]) % mod < 4 * cur && l1 < mid) l1 ++;
			while ((a[0] + b[l2]) % mod < 4 * cur && l2 < (1<<cnt2)) l2 ++;
			for (int i=0;i<(1<<cnt1);i++) {
				while (mid && a[i] % mod + b[mid-1] % mod >= 10 * cur) mid --;
				r1 = min(r1,mid-1);
				while (r1  >=  0   && (a[i] + b[r1]) % mod >= 5 * cur) r1 --;
				while (l1  >   0   && (a[i] + b[l1-1]) % mod >= 4 * cur) l1 --;
				while (r2  >=  mid && (a[i] + b[r2]) % mod >= 5 * cur) r2 --;
				while (l2  >   mid && (a[i] + b[l2-1]) % mod >= 4 * cur) l2 --;
				ans += (r1 - l1 + 1) + (r2 - l2 + 1);
			}
			cur *= 10;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
