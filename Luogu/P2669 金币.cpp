#include <iostream>
using namespace std;
int main(){
    int k;
    cin >> k;
    int a = 1;
    int b = 0;
    int tot = 0;
    for (int i=1;i<=k;i++){
        b ++;
        tot += a;
        if (b == a){
            a ++;
            b = 0;
        }
    }
    cout << tot << endl;
}