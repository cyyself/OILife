#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main(){
    string raw;
    cin >> raw;
    string result;
    if (raw[0] == '-') cout << "-";
    bool flag = false;
    for (int i=raw.length()-1;i>=0;i--){
        if (raw[i] == '0' && !flag) continue;
        if (raw[i] != '0') flag = true;
        if (raw[i] == '-') continue;
        result += raw[i];
    }
    cout << result << endl;
    return 0;
}