#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
string capitaltosmall(string str){//这个函数用于把所有小写字母转换为大写字母
    for (int i=0;i<str.length();i++){
        if (str[i] >= 65 && str[i] <= 96){//在ASCII码中，65为大写A，96为大写Z，97开始为小写a，以此类推
            str[i] += 32;//大小写差值为32
        }
    }
    return str;
}
int main(){
    int touchvalue = 0;//感动值
    vector <string> dic;//可以被感动的单词字典
    int n;//需要输入字典的单词数量
    cin >> n;//输入n
    for (int i=0;i<n;i++){
        string temp;
        cin >> temp;
        temp = capitaltosmall(temp);
        dic.push_back(temp);
    }//将可以被感动单词读入字典
    string str;
    cin.get();
    /*
    重点，也是最容易遇到的问题
    cin的原理是从std::in中读取输入流，没有输入流那么就请求键盘输入。
    键盘输入是先输入到缓冲区中的。
    cin命令对结束符（换行'\n'、空格' '、Tab'    '）的处理方式是，
    丢弃缓冲区中使得输入结束的结束符。也不会返回这个字符。
    在输入最后一个单词后，按下了Enter键，输入了一个'\n'，
    但是这个‘\n’并没有被cin截获，它还在输入缓冲区中。
    cin.get()的结束符可自定义，默认为换行'\n'，
    需要注意的是，cin.get()读取的数据会包括结束符，
    这时，cin.get()意义就在这，它把这个Enter读取出来，
    尽管cin.get的返回结果是一个字符串结束符'\n'
    但是解决了一个Enter没有被读取的问题，这样getline就不会读到这个'\n'，
    getline就会继续请求输入并截取到回车为止。
    */
    getline(cin,str);
    str = capitaltosmall(str);//让全部的大写字母转换为小写字母
    //文本分割代码参见https://github.com/cyyself/strsplit/blob/master/strsplit.cpp
    //类似C#和VB.net中String类型的split函数
    string separator = ".";//
    vector <string> sentences;//存储一个个句子的变量
    int i=0;
    string temp = "";
    while(i != str.length()){
        if (str[i] == separator[0]){
                //matched
                i += 1;
                if (temp != "") sentences.push_back(temp);//ignore empty
                temp = "";
                continue;
        }
        temp += str[i];
        i++;
    }//原理大概就是，一个个字符读入temp，如果读到了英文句号（separator的内容），就把之前读入到temp的字符push到sentences中。
    if (temp != ""){
        sentences.push_back(temp);
    }//如果最后一个句子没有句号，就把目前已经读取到的再读入数组中。
    for (int i=0;i<sentences.size();i++){//replace all comma to space
        while(sentences[i].find(",",0) != string::npos){
            sentences[i].replace(sentences[i].find(",",0),1," ");
        }
    }//把所有句子的逗号都换成空格，防止邪恶的lin_toto出一个逗号后面不加空格句子来卡测试点。
    for (int i=0;i<sentences.size();i++){//之后就是对每个句子进行分割，以空格为界限分割出单词，然后判断
        //其实后来觉得自己这样写有点傻，直接用find函数前后加上空格，每个句子前后补上空格就行。
        int touchvaluetemp = 0;
        vector <bool> indic;
        for (int i=0;i<dic.size();i++){
            indic.push_back(false);
        }
        str = sentences[i];
        separator = " ";
        vector <string> result;
        int j=0;
        temp = "";
        while(j != str.length()){
            if (str[j] == separator[0]){
                if (str.substr(j,separator.size()) == separator){
                    //matched
                    j += separator.length();
                    if (temp != "") result.push_back(temp);//ignore empty
                    temp = "";
                    continue;
                }
            }
            temp += str[j];
            j++;
        }
        if (temp != ""){
            result.push_back(temp);
        }
        //至此完成本句子的文本分割
        for (int j=0;j<result.size();j++){
            for (int k=0;k<dic.size();k++){
                if (result[j] == dic[k]){
                    indic[k] = true;
                }
            }
        }
        //至此完成匹配单词
        for (int i=0;i<dic.size();i++){
            if (indic [i]) touchvaluetemp ++;
        }
        touchvalue += touchvaluetemp;
        //至此完成感动值计算
    }
    cout << touchvalue << endl;//输入感动值
    return 0;
}