#include <cstdio>
using namespace std;
int a[10000005];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=2;i<=m;i++)
        if (a[i] == 0){
            for (int j=i;j<=m/i;j++) a[i*j] = 1;
            a[i] = 1;
        }
        else{
            a[i] = 0;
        }
    for (int i=1;i<=m;i++) a[i] = a[i] + a[i-1];
    for (int i=1;i<=n;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        if (l < 1 || r < 1 || l > m || r > m){
            printf("Crossing the line\n");
            continue;
        }
        printf("%d\n",a[r]-a[l-1]);
    }
    return 0;
}