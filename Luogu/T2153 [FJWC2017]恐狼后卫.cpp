#include <cstdio>
#include <algorithm>
using namespace std;
int n,atk;
int b[405];
int t[405];//t[i]表示打死第i只狼所需要的次数
int f[405][405];
int main() {
    //freopen("wolf.in","r",stdin);
    //freopen("wolf.out","w",stdout);
    scanf("%d%d",&n,&atk);
    int ans = 0;
    //易证我们把一只狼一只打直到死和每次换着打不同的狼只要打死狼的顺序相同最终结果是没有区别的
    for (int i=1;i<=n;i++) {//预处理，先把杀死第i只狼所需次数和不考虑恐狼后卫情况下杀死的狼的最优解求出
        int a,h;
        scanf("%d%d%d",&a,&b[i],&h);
        t[i] = h / atk;
        if (h % atk) t[i] ++;
        ans += t[i] * a;
    }
    //由此我们可列DP方程：f[i][j]=Min(f[i][k-1]+f[k+1][j]+(b[i-1]+b[j+1])* times[k])
    //其中f[i][j]表示打死第i只狼到第j只狼的最小伤害值
    for (int l=1;l<=n;l++) {//区间DP传统，一个len从1开始
        for (int i=1;i<=n-l+1;i++) {
            int j = i + l - 1;
            f[i][j] = 0x3fffffff;
            for (int k=i;k<=j;k++) {//在i到j的区间中，我们枚举最后打的狼为k，通过枚举k判断最后打哪一个可以使得伤害值最小
                //这里详细解释一下，因为我们在i到j的区间中最后打的狼为k，所以在这个区间中最后打第k只狼时受到的随从伤害为（b[i-1]+b[j+1])*t[k]
                int tmp = f[i][k-1] + f[k+1][j];
                tmp += t[k] * b[i-1];//如果数组没有多开的话注意处理边界问题
                tmp += t[k] * b[j+1];
                f[i][j] = min(f[i][j],tmp);
            }
        }
    }
    ans += f[1][n];
    printf("%d\n",ans);
    return 0;
}
