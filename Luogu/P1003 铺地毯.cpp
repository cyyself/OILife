#include <iostream>
using namespace std;
struct square
{
    int a,b,g,k;
    bool insquare(int x,int y){
        if (x >= a && y >= b && x <= a+g && y <= b+k){
            return true;
        }
        return false;
    }
};
int main(){
    int n;
    cin >> n;
    square set[100001] ;
    for (int i=0;i<n;i++){
        int a,b,g,k;
        cin >> a;
        cin >> b;
        cin >> g;
        cin >> k;
        set[i].a = a;
        set[i].b = b;
        set[i].g = g;
        set[i].k = k;
    }
    int top = -1;
    int x,y;
    cin >> x;
    cin >> y;
    for (int i=n-1;i>=0;i--){
        if (set[i].insquare(x,y)){
            top = i + 1;
            break;
        }
    }
    cout << top << endl;
    return 0;
}