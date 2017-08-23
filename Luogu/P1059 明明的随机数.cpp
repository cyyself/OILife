#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int c;
    cin >> c;
    int n[100];
    int num[10001];
    memset(num,0,sizeof(num));
    for (int i=0;i<c;i++){
        cin >> n[i];
        num[n[i]]++;
    }
    int r = 0;
    for (int i=0;i <= 10000;i++) {
        if (num[i] != 0){
            r++;
        }
    }
    cout << r << endl;
    for (int i=0;i <= 10000;i++){
        if (num[i] != 0){
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}