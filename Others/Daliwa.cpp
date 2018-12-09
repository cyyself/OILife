/*
	很可惜重庆市赛考场上想到了这个方法但是细节没写好最后样例都没过。最后因为A题罚时太高只拿了二等奖回来。

	大体思路：
		因为当i>=3时，f[i] = a * f[i-2] + b * f[i-1]
		所以可以确保一点，对于f[i]>=3的情况，我们可以开一个sum数组
		然后sum[i] = a * sum[i-2] + b * sum[i-1]
		之后把sum[i]再加到x[i]上
		但是此时还有一个问题，就是f[1]和f[2]的情况要特殊处理

		比如说，两个query，分别是[1,2]和[2,3]
		那么计算sum[3]的时候，如果直接计算sum[i] = a * sum[i-2] + b * sum[i-1]
		就会导致一个应该是f[2]的地方被算成b * f[1] + a * 0

		这个时候，我们可以开两个数组，f1cnt[n]和f2cnt[n]，用于记录这个地方要加上的f[1]和f[2]的数量

		然后在计算sum的时候，对于sum[i-1]的情况，要忽略掉这里的f[1]

		最后得到以下式子：
		sum[i] = b * (sum[i-1] - f1cnt[i-1] * f[1]) + a * sum[i-2] + f1cnt[i] * f[1] + f2cnt[i] * f[2]

		接下来就是记录每个位置所要做的操作，当一个f[1]开始的时候，让f1cnt[i]++和f2cnt[i+1]++

		之后计算sum[i]，并把sum[i]加到x[i]上

		当走到某个query的r的时候，让sum[i]和sum[i-1]减去对应的f，防止在下次计算的时候继续递推

		但是这里又有一个问题，如果区间长度等于2，特判有点麻烦（因为计算sum的时候减去了前面的f[1]）
		所以我们不妨直接在读入query的时候，当r-l+1<=2时，用O(1)的复杂度直接把操作加到x上

		至于对于每个query的l和r打标记的问题，我自己的做法是开一个struct，记录两个参数，位置x和操作类型。
		操作类型包括两种：
			1. f[1]的开始(我的程序里写的是0)
			2. f[r-l+1]在这个位置结束

		然后对x排序，把f[1]开始排在前面

		后来出了考场听我们学校一个大佬说可以开n个vector来记录这些在每个位置的操作，这样时间复杂度更低一些

		之后这题就弄完了
		
		qwq
*/
#include <bits/stdc++.h>
using namespace std;
const long long mo = 1e9+7;
long long sum[100005];
long long f1cnt[100005];
long long f2cnt[100005];
long long x[100005];
long long f[100005];
long long a,b;
struct query{
	int x;
	int type;//0开始，!0
	friend bool operator < (const query &a,const query &b) {
		if (a.x < b.x) {
			return true;
		}
		else {
			if (a.x == b.x) return a.type < b.type;
			else return false;
		}
	}
}qu[200005];
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		memset(sum,0,sizeof(sum));
		memset(f1cnt,0,sizeof(f1cnt));
		memset(f2cnt,0,sizeof(f2cnt));
		int n,q;
		scanf("%d%d",&n,&q);
		scanf("%lld%lld",&f[1],&f[2]);
		scanf("%lld%lld",&a,&b);
		for (int i=1;i<=n;i++) scanf("%lld",&x[i]);
		f[1] %= mo;
		f[2] %= mo;
		for (int i=3;i<=n;i++) {
			f[i] = a * f[i-2] + b * f[i-1];
			f[i] %= mo;
		}
		int qcnt = 0;
		while (q --) {
			int l,r;
			scanf("%d%d",&l,&r);
			if (l == r) {
				x[l] += f[1];
				x[l] %= mo;
			}
			else {
				if (l + 1 == r) {
					x[l] += f[1];
					x[l] %= mo;
					x[r] += f[2];
					x[r] %= mo;
				}
				else {
					qu[qcnt++] = (query){l,0};
					qu[qcnt++] = (query){r,r-l+1};
				}
			}
		}
		sort(qu,qu+qcnt);
		int head = 0;
		for (int i=1;i<=n;i++) {
			while (head < qcnt && qu[head].x == i && qu[head].type == 0) {
				f1cnt[i]   ++;
				f2cnt[i+1] ++;
				head ++;
			}
			if (i == 1) sum[i] = f1cnt[i] * f[1];
			else sum[i] = b * (sum[i-1] - f1cnt[i-1] * f[1]) + a * sum[i-2] + f1cnt[i] * f[1] + f2cnt[i] * f[2];
			sum[i] += mo;
			sum[i] %= mo;
			x[i] += sum[i];
			x[i] %= mo;
			while (head < qcnt && qu[head].x == i && qu[head].type != 0) {
				sum[i] -= f[qu[head].type];
				sum[i] += mo;
				sum[i] %= mo;
				sum[i-1] -= f[qu[head].type-1];
				sum[i-1] += mo;
				sum[i-1] %= mo;
				head ++;
			}
		}
		for (int i=1;i<=n;i++) {
			if (i != 1) printf(" ");
			printf("%lld",x[i]);
		}
		printf("\n");
	}
	return 0;
}
