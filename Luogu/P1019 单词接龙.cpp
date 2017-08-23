#include <cstring>
#include <iostream>
using namespace std;
int n;//单词数量
string dic[22];//元素索引从0到n-1用来存储单词，n为开头字符
int sel[22] = {0};//被选中的次数
string search(int now,int last,bool first){
    string temp;//当前搜索的临时变量，最终用来返回一条“龙”
    if (first == true){//判断是否为第一次，以决定不同的判断该字符串是否与上次搜索使用的字符串可以连接的方式。
        if (dic[now][0] == dic[last][0]){
            temp = dic[now];
        }else{
            return "";//无法继续搜索
        }
    }else{
        bool available = false;
        for (unsigned long i=1;i<=min(dic[last].length(),dic[now].length());i++){
            string check =dic[last].substr(dic[last].length()-i);
            if (check == dic[now].substr(0,i)){//如果上次字符串的位置从结束到i和当前字符串位置从0到i相等
                available = true;//那么就标记当前搜索的单词可以被使用
                temp = dic[now].substr(i);//把这个单词的后面的部分放进去
                break;
            }
        }
        if (!available) return "";//无法继续搜索
    }
    string t1 = "";//用来存储多次搜索后搜到的最长单词
    for (int i=0;i<n;i++){
        string t2 = "";////用来存储本次搜索后搜到的最长单词
        if (sel[i] < 2){
            sel[i]++;
            t2 = search(i,now,false);//DFS，没啥好说的
            sel[i]--;
            if (t2.length() > t1.length()) t1 = t2;
        }
    }
    temp += t1;
    return temp;
}
int main(){
    cin >> n;
    for (int i=0;i<n;i++) cin >> dic[i];
    cin >> dic[n];//开头字符
    unsigned long ans = 0;
    for (int i=0;i<n;i++){
        sel[i]++;
        unsigned long temp = search(i,n,true).length();
        sel[i]--;
        if ( temp > ans ) ans = temp;
        //cout << search(i,n,true) << endl;
    }
    cout << ans << endl;
    return 0;
}