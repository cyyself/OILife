#include <iostream>
#include <algorithm>//sort函数需要头文件algorithm
using namespace std;
struct competitor{
    int sequence;//顺序（编号）
    int score;//分数
    int weight;//实力值
};//用struct取代多个变量，使代码更易读
competitor competitors[200005],a[100005],b[100005];
bool comps(competitor x, competitor y) {
    if (x.score < y.score) return false;
    if (x.score == y.score)
        if (x.sequence > y.sequence) return false;
    return true;
}//给sort函数所使用的判断函数，来定义sort函数先按照分数排序，再按照顺序排序。
//sort函数的第三个参数简单来说，就是把你认为要放前面的放回true，否则返回false，千万不要空返回，不然就变成随机排序了
/*
当然也可以这样写：
bool comps(competitor x, competitor y) {
    if (x.score > y.score) return true;
    if (x.score == y.score)
        if (x.sequence < y.sequence) return true;
    return false;
}
*/
int main(){
    int n,r,q,counta,countb,i,j,count;
    cin>>n>>r>>q;
    for(i=0;i<2*n;i++) scanf("%d",&competitors[i].score);
    for(i=0;i<2*n;i++){
        scanf("%d",&competitors[i].weight);//用scanf取代cin，防止大数据输入超时
        competitors[i].sequence=i+1;
    }
    //输入数据
    sort(competitors,competitors+n*2,comps);
    for(i=1;i<=r;i++){
        for(j=0;j<2*n;j+=2)
            if(competitors[j].weight>competitors[j+1].weight){
                competitors[j].score++;//加分
                a[j/2]=competitors[j];//胜者
                b[j/2]=competitors[j+1];//负者
            }
            else{
                competitors[j+1].score++;//同上，反过来
                a[j/2]=competitors[j+1];
                b[j/2]=competitors[j];
            }
        counta=0;
        countb=0;
        count=-1;
        while(counta!=n||countb!=n){//归并排序
            count++;
            if (counta == n){
                competitors[count]=b[countb];
                countb++;
                continue;
            }
            if (countb == n){
                competitors[count]=a[counta];
                counta++;
                continue;
            }
            if (a[counta].score > b[countb].score){
                competitors[count]=a[counta];
                counta++;
            }
            else{
                if (a[counta].score == b[countb].score && a[counta].sequence < b[countb].sequence){
                    competitors[count]=a[counta];
                    counta++;
                }else{
                    competitors[count]=b[countb];
                    countb++;
                }
            }
        }
    }
    cout<<competitors[q-1].sequence;
    return 0;
}