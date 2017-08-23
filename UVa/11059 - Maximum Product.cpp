#include <cstdio>
using namespace std;
int array[18];
int main(){
    int n;
    int casen = 1;
    while(scanf("%d",&n) == 1){
        long long ans = 0;
        for (int i=0;i<n;i++) scanf("%d",&array[i]);
        for (int i=0;i<n;i++)
            for (int j=i;j<n;j++){
                long long t = 1;
                for (int k=i;k<=j;k++) t *= array[k];
                if (t > ans) ans = t;
            }
        printf("Case #%d: The maximum product is %lld.\n\n",casen,ans);
        casen++;
    }
    return 0;
}