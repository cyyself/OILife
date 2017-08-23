#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int A,B,L;
    cin >> A >> B >> L;
    double d = (double)A/B;
    int ansA,ansB;
    double ansd = 1;
    for (int i=1;i<=L;i++){
        for (int j=1;j<=L;j++){
            double t = (double)i/j;
            if (t >= d && abs(t - d) < ansd){
                ansd = abs(t - d);
                ansA=i;
                ansB=j;
            }
        }
    }
    cout << ansA << " " << ansB << endl;
    return 0;
}