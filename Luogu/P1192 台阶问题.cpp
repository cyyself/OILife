#include <iostream>
using namespace std;
int main(){
    long long n,k;
    cin >> n >> k;
    long long number [100100]  = {0};
    number[k-1] = 1;
    for (long long i=k;i<=n+k-1;i++){
        for (long long j=i-1;j>=i-k;j--){
            number[i] = (number[i] + number[j]) % 100003;
        }
    }
    cout << number[n+k-1] << endl;
    return 0;
}