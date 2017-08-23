#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);//输入a,b,c
    bool available = false;//默认标记无解
    for (int i=100;i<=1000/(max(a,max(b,c))/a);i++){//max(x,max(y,z))即为求出a,b,c三个数中的最大值，只需要枚举到1000/(max/a)即可
        char x[4],y[4],z[4];//字符串结束符占用一个字符空间
        sprintf(x,"%d",i);//将int转换为char，方便十进制处理
        sprintf(y,"%d",(int)i*b/a);
        sprintf(z,"%d",(int)i*c/a);
        bool num[10] = {0};
        num[x[0]-48] = true;//ascii码中，0-9对应48-57
        num[x[1]-48] = true;
        num[x[2]-48] = true;
        num[y[0]-48] = true;
        num[y[1]-48] = true;
        num[y[2]-48] = true;
        num[z[0]-48] = true;
        num[z[1]-48] = true;
        num[z[2]-48] = true;
        if (num[0]) continue;//题目要求1-9的数字，出现0即为Wrong Answer
        int count = 0;
        for (int i=0;i<10;i++) if (num[i]) count ++;
        if (count == 9){//9个数都存在
            available = true;//标记有解
            printf("%s %s %s\n",x,y,z);//输出
        }
    }
    if (!available) printf("No!!!");//无解
    return 0;
}