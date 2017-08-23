#include <iostream>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    for (int i=1;i<=n;i++){
        if (i % k == 0) n++;
    }
    cout << n << endl;
    return 0;
}