#include <iostream>
#include <cstring>
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
int main(){
    string a,b;
    cin >> a >> b;
    cout << sum(a,b) << endl;
    return 0;
}