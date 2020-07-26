#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int a[maxn];
vector<pair<int,int> > interR[maxn];//L,and sum
struct TR {
    int l,r;
    int sum;
}t[maxn*30*20*2];
int nodecnt;
void add(int &node,int l,int r,int x,int d) {
    t[++nodecnt] = t[node];
    node = nodecnt;
    t[node].sum += d;
    if (l != r) {
        int mid = (l + r) >> 1;
        if (x <= mid) add(t[node].l,l,mid,x,d);
        else add(t[node].r,mid+1,r,x,d);
    }
}
int sum(int node,int l,int r,int L,int R) {
    if (L <= l && r <= R) return t[node].sum;
    else {
        int mid = (l + r) >> 1;
        int res = 0;
        if (L <= mid) res += sum(t[node].l,l,mid,L,R);
        if (R > mid) res += sum(t[node].r,mid+1,r,L,R);
        return res;
    }
}
int rt[maxn];
int main() {
    nodecnt = 0;
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    interR[1].emplace_back(1,a[1]);
    for (int i=2;i<=n;i++) {
        int last = a[i];
        interR[i].emplace_back(i,last);
        for (auto x:interR[i-1]) {
            if ((last & x.second) != last) {
                last &= x.second;
                interR[i].emplace_back(x.first,last);
            }
        }
    }
    map <int,int> MAX;
    for (int i=1;i<=n;i++) {
        rt[i] = rt[i-1];
        for (auto x:interR[i]) {
            if (x.first >= MAX[x.second]) {
                add(rt[i],1,n,x.first,1);
                if (MAX[x.second]) add(rt[i],1,n,MAX[x.second],-1);
                MAX[x.second] = x.first;
            }
        }
    }
    int q;
    scanf("%d",&q);
    int lastans = 0;
    while (q --) {
        int l,r;
        scanf("%d%d",&l,&r);
        l = (l ^ lastans) % n + 1;
        r = (r ^ lastans) % n + 1;
        if (l > r) swap(l,r);
        lastans = sum(rt[r],1,n,l,r);
        printf("%d\n",lastans);
    }
    return 0;
}
