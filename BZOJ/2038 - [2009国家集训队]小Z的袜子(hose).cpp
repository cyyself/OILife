#include <bits/stdc++.h>
using namespace std;
int a[50005];
int pos[50005];
struct query {
    int l,r,id;
    void read(int _id) {
        scanf("%d%d",&l,&r);
        id = _id;
    }
    friend bool operator < (const query &a,const query &b) {
        if (pos[a.l] == pos[b.l]) return a.r < b.r;
        return pos[a.l] < pos[b.l];
    }
}q[50000];
pair<long long,long long> ans[50000];
int n,m;
long long cnt[50005];
long long cur;
void add(int x) {
    cur -= cnt[a[x]] * (cnt[a[x]] - 1);
    cnt[a[x]] ++;
    cur += cnt[a[x]] * (cnt[a[x]] - 1);
}
void del(int x) {
    cur -= cnt[a[x]] * (cnt[a[x]] - 1);
    cnt[a[x]] --;
    cur += cnt[a[x]] * (cnt[a[x]] - 1);
}
long long gcd(long long a,long long b) {
    if (b == 0) return a;
    return gcd(b,a%b);
}
int main() {
    while (scanf("%d%d",&n,&m) == 2) {
        memset(cnt,0,sizeof(cnt));
        cur = 0;
        int bs = sqrt(n);
        for (int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            pos[i] = i / bs;
        }
        for (int i=0;i<m;i++) q[i].read(i);
        sort(q,q+m);
        int l=1,r=0;
        for (int i=0;i<m;i++) {
            while (l < q[i].l) del(l++);
            while (l > q[i].l) add(--l);
            while (r < q[i].r) add(++r);
            while (r > q[i].r) del(r--);
            long long fz = cur;
            long long fm = (q[i].r - q[i].l + 1LL) * (q[i].r - q[i].l);
            if (fz == 0 || fm == 0) {
                fz = 0;
                fm = 1;
            }
            else {
                long long g = gcd(fz,fm);
                fz /= g;
                fm /= g;
            }
            ans[q[i].id] = make_pair(fz,fm);
        }
        for (int i=0;i<m;i++) printf("%lld/%lld\n",ans[i].first,ans[i].second);
    }
    return 0;
}
