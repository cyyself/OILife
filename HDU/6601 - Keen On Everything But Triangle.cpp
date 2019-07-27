#include <bits/stdc++.h>
using namespace std;
int a[100005];
struct DATA {
    int v,pos;
    friend bool operator < (const DATA &a,const DATA &b) {
        return a.v < b.v;
    }
}d[100005];
struct Tr {
    int l,r;
    int sum;
}t[30*1000005];
int ncnt;
int create(int node) {
    ncnt ++;
    t[ncnt].l = t[node].l;
    t[ncnt].r = t[node].r;
    t[ncnt].sum = t[node].sum;
    return ncnt;
}
inline void push_up(int node) {
    t[node].sum = t[t[node].l].sum + t[t[node].r].sum;
}
void insert(int node,int l,int r,int pos) {
    if (l == r) {
        t[node].sum ++;
    }
    else {
        int mid = (l + r) >> 1;
        if (pos <= mid) {
            t[node].l = create(t[node].l);
            insert(t[node].l,l,mid,pos);
        }
        else {
            t[node].r = create(t[node].r);
            insert(t[node].r,mid+1,r,pos);
        }
        push_up(node);
    }
}
int query(int x,int y,int l,int r,int k) {
    int cur = t[t[y].r].sum - t[t[x].r].sum;
    if (l == r) return l;
    else {
        int mid = (l + r) >> 1;
        if (k <= cur) return query(t[x].r,t[y].r,mid+1,r,k);
        else return query(t[x].l,t[y].l,l,mid,k-cur);
    }
}
int rk[100005];
int rt[100005];
int main() {
    int n,q;
    while (scanf("%d%d",&n,&q) == 2) {
        ncnt = 0;
        for (int i=1;i<=n;i++) {
            scanf("%d",&d[i].v);
            d[i].pos = i;
        }
        sort(d+1,d+1+n);
        for (int i=1;i<=n;i++) rk[d[i].pos] = i;
        for (int i=1;i<=n;i++) {
            rt[i] = create(rt[i-1]);
            insert(rt[i],1,n,rk[i]);
        }
        while (q --) {
            int l,r;
            scanf("%d%d",&l,&r);
            int len = r - l + 1;
            if (len < 3) {
                printf("-1\n");
                continue;
            }
            else {
                int rk1 = query(rt[l-1],rt[r],1,n,1);
                int rk2 = query(rt[l-1],rt[r],1,n,2);
                int rk3 = query(rt[l-1],rt[r],1,n,3);
                int cnt = 3;
                bool flag = false;
                while (cnt <= 50) {
                    if (d[rk2].v + d[rk3].v > d[rk1].v) {
                        flag = true;
                        printf("%lld\n",1ll*d[rk1].v + d[rk2].v + d[rk3].v);
                        break;
                    }
                    if (cnt + 1 > len) break;
                    rk1 = rk2;
                    rk2 = rk3;
                    rk3 = query(rt[l-1],rt[r],1,n,++cnt);
                }
                if (!flag) printf("-1\n");
            }
        }
    }
    return 0;
}
