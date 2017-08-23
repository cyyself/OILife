#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
string sum(string x, string y){
    string nx;
    string ny;
    for (int i=x.length()-1;i>=0;i--) nx += x[i]-48;
    for (int i=y.length()-1;i>=0;i--) ny += y[i]-48;
    //翻转数字
    string result;
    int add = 0;
    bool longer;//为true时x大于y
    if (nx.length() > ny.length()){
        longer = true;
    }
    else{
        longer = false;
    }
    for (int i=0;i<min(x.length(),y.length());i++){
        result += (nx[i]+ny[i]+add)%10;
        add = (nx[i]+ny[i]+add)/10;
    }
    for (int i=min(x.length(),y.length());i<max(nx.length(),ny.length());i++){
        if (longer){
            result += (nx[i] + add)%10;
            add = (nx[i] + add)/10;
        }
        else{
            result += (ny[i] + add)%10;
            add = (ny[i] + add)/10;
        }
    }
    if (add > 0){
        result += add;
    }
    string final;
    for (int i=result.length()-1;i>=0;i--) final += result[i]+48;
    return final;
}
string multi(string x, string y){
    string nx;
    string ny;
    for (int i=x.length()-1;i>=0;i--) nx += x[i]-48;
    for (int i=y.length()-1;i>=0;i--) ny += y[i]-48;
    //翻转数字
    string result;
    for (int i=0;i<x.length();i++){
        string t;
        int add = 0;
        for (int j=0;j<y.length();j++){
            int n = nx[i] * ny[j] + add;
            add = n / 10;
            t += n % 10;
        }
        string t2;
        if (add != 0)t += add;
        for (int j=t.length()-1;j>=0;j--) t2 += t[j]+48;
        string z;
        for (int j=1;j<=i;j++) z += "0";
        result = sum(result,t2 + z);
    }
    return result;
}
int main(){
    int n;
    cin >> n;
    string result;
    for (int i=1;i<=n;i++){
        string t = "1";
        for (int j=2;j<=i;j++){
            char t1[100];
            sprintf(t1,"%d",j);
            t = multi(t,t1);
        }
        result = sum(result,t);
    }
    cout << result << endl;
    return 0;
}