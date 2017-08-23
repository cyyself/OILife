#include <cstdio>
using namespace std;
int main(){
    for (int i=123;i<=333;i++){
        char a[4],b[4],c[4];//字符串结束符占用一个字符空间
        sprintf(a,"%d",i);//将int转换为char
        sprintf(b,"%d",i*2);
        sprintf(c,"%d",i*3);
        bool num[10] = {0};
        num[a[0]-48] = true;//ascii码中，0-9对应48-57
        num[a[1]-48] = true;
        num[a[2]-48] = true;
        num[b[0]-48] = true;
        num[b[1]-48] = true;
        num[b[2]-48] = true;
        num[c[0]-48] = true;
        num[c[1]-48] = true;
        num[c[2]-48] = true;
        if (num[0]) continue;//题目要求1-9的数字，出现0即为Wrong Answer
        int count = 0;
        for (int i=0;i<10;i++) if (num[i]) count ++;
        if (count == 9){
            printf("%s %s %s\n",a,b,c);
        }
    }
    return 0;
}