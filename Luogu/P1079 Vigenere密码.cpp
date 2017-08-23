#include <iostream>
using namespace std;
int main(){
    string str;
    string key;
    getline(cin,key);
    getline(cin,str);
    for (int i=0;i<key.length();i++) if (key[i] >= 'A' && key[i] <= 'Z') key[i] += 32;//大写转小写
    int keyIndex = 0;//当前使用的密钥在Key中的位置
    for (int i=0;i<str.length();i++){
        int a = str[i] - key[keyIndex] + 'a';
        if (str[i] >= 'a'){
            if (a < 'a') a += 26;
        }
        else{
            if (a < 'A') a += 26;
        }
        str[i] = char(a);//将ascii转换为char（注意，a不能为char，否则大于128时会溢出变为负数）
        keyIndex++;
        if (keyIndex >= key.length()) keyIndex = 0;//Key索引到尾部，则重头开始
    }
    for (int i=0;i<str.length();i++) cout << str[i];//输出
    return 0;
}