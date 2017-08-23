#include <iostream>
using namespace std;
int main(){
    long l,m;
    cin>>l>>m;
    int tree[10001] = {0};
    for (int i=0;i<m;i++){
        long l1,l2;
        cin>>l1>>l2;
        for (int i2 = l1;i2<=l2;i2++){
            tree[i2] = 1;
        }
    }
    int out = l + 1;
    for (int i=0;i<=l;i++) {
        if (tree[i] == 1){
            --out;
        }
    }
    cout<<out<<endl;
    return 0;
}