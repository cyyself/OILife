#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
bool judge[maxn];
vector <long long> primes;
long long pre[maxn];
inline void getprime(int x) {
	judge[1] = true;
	for (int i=2;i<=x;i++) {
		if (!judge[i]) primes.push_back(i);
		for (auto p:primes) {
			if (i * p > x) break;
			judge[i*p] = true;
			pre[i*p] = p;
			if (i % p == 0) break;
		}
	}
}
vector<long long> each_p[maxn];//每个数对应的质因子
vector<long long> each_n[maxn];//每个质因子对应的数
long long minp[maxn];//每个数的最小质因子
bool vis[maxn];
int main() {
	getprime(2e5);
	int T;
	scanf("%d",&T);
	while (T --) {
		int n;
		scanf("%d",&n);
		vector <long long> allp;
		for (int i=2;i<=n;i++) {
			vis[i] = false;
			map <long long,int> cnt;
			long long ii = i;
			while (pre[ii]) {
				cnt[pre[ii]] ++;
				ii /= pre[ii];
			}
			cnt[ii] ++;
			for (auto x:cnt) {
				allp.push_back(x.first);
				each_n[x.first].push_back(i);
				each_p[i].push_back(x.first);
			}
			minp[i] = cnt.begin()->first;
		}
		sort(allp.begin(),allp.end());
		allp.erase(unique(allp.begin(),allp.end()),allp.end());
		vector <pair<int,int> > ans;
		for (int i=(int)allp.size()-1;i>=0;i--) {
			vector <long long> cur;
			for (auto x:each_n[allp[i]]) if (!vis[x]) cur.push_back(x);
			if (cur.size() & 1) {
				int pos = 0;
				for (int j=0;j<cur.size();j++) if (minp[cur[j]] < minp[cur[pos]]) pos = j;
				vector <long long> cur2;
				for (int j=0;j<cur.size();j++) if (j != pos) cur2.push_back(cur[j]);
				for (int j=0;j<cur2.size();j+=2) {
					ans.emplace_back(cur2[j],cur2[j+1]);
					vis[cur2[j]] = true;
					vis[cur2[j+1]] = true;
				}
			}
			else {
				for (int j=0;j<cur.size();j+=2) {
					ans.emplace_back(cur[j],cur[j+1]);
					vis[cur[j]] = true;
					vis[cur[j+1]] = true;
				}
			}
		}
		for (int i=2;i<=n;i++) {
			each_p[i].clear();
		}
		for (auto x:allp) each_n[x].clear();
		printf("%d\n",(int)ans.size());
		for (auto x:ans) {
			printf("%d %d\n",x.first,x.second);
		}
	}
	return 0;
}
