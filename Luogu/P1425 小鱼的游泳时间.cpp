#include <iostream>
using namespace std;
int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int m = d-b;
    if (m < 0){
        m += 60;
        c--;
    }
    cout << c-a << " " << m << endl;
    return 0;
}