#include <bits/stdc++.h>
using namespace std;
int arr[505];
int pos[505];
bool vis[505];//对应的数是否已经放了
int s[505];
int LIS(vector <int> a) {
    s[0] = 0;
    int tail = 0;
    for (int i=0;i<a.size();i++) {
        if (a[i] > s[tail]) {
            s[++tail] = a[i];
            continue;
        }
        int p = upper_bound(s,s+tail,a[i]) - s;
        s[p] = a[i];
    }
    return tail;
}
int main() {
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%d",&arr[i]);
    }
    int ans = n;
    for (int i=1;i<=n;i++) {
        vector <int> tmp;
        for (int j=i;j<=n;j++) tmp.push_back(arr[j]);
        for (int j=1;j<i;j++) tmp.push_back(arr[j]);
        ans = min(ans,n-LIS(tmp));
    }
    printf("%d\n",ans);
    return 0;
}
