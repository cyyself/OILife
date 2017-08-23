#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n,q;
int p = 0;
int link[500005];
int cnt[500005];//环的大小
int cmap[500005];
struct zys{
    int n;//数字
    int s;//数量
    zys():n(0),s(0){}
};
vector <zys> l;
void search(int source) {
    if (cmap[source] != 0) return;
    int curr = source;
    p++;
    while(cmap[curr] == 0) {
        cmap[curr] = p;
        cnt[p] ++;
        curr = link[curr];
    }
}
void fjzys(int num) {
    zys curr;
    for (int i=2;i<=num;i++) while (num % i == 0) {
        //此时i是num的一个质因数
        num /= i;
        if (i == curr.n) curr.s ++;
        else {
            if (curr.n != 0) l.push_back(curr);
            curr.n = i;
            curr.s = 1;
        }
    }
    if (curr.n != 0) l.push_back(curr);
}
bool comp(const zys &a,const zys &b) {
    if (a.n < b.n) return true;
    if (a.n == b.n && a.s > b.s) return true;
    return false;
}
long long qpow(long long di,long long zhi,long long mod) {
    if (zhi == 0) return 1 % mod;
    if (zhi == 1) return di % mod;
    long long ret = qpow(di,zhi/2,mod) % mod;
    ret = (ret * ret) % mod;
    if (zhi % 2) ret = ret * (di % mod);
    return ret % mod;
}
int main() {
    //freopen("geronimo.in","r",stdin);
    //freopen("geronimo.out","w",stdout);
    scanf("%d%d",&n,&q);
    for (int i=0;i<n;i++) {
        int v;
        scanf("%d",&v);
        v--;
        link[v] = i;
    }
    if (q == 1) {
        printf("0\n");
        return 0;
    }
    for (int i=0;i<n;i++) search(i);
    sort(cnt+1,cnt+1+p);
    if (cnt[p] == 0) printf("0\n");
    else {
        int px = 0;
        for (int i=1;i<=p;i++) if (cnt[i] > 1 && cnt[i] != cnt [i-1]) {
            fjzys(cnt[i]);
        }
        sort(l.begin(),l.end(),comp);
        long long lcm = qpow(l[0].n,l[0].s,q);
        for (int i=1;i<l.size();i++) {
            if (l[i].n == l[i-1].n) continue;
            lcm = (lcm * qpow(l[i].n,l[i].s,q))%q;
        }
        printf("%lld\n",lcm);
    }
    return 0;
}
