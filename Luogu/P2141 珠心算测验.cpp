#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 0;
    int array[100];
    bool flag[100]= {0};
    for (int i=0;i<n;i++) cin >> array[i];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            for (int k=0;k<n;k++){
                if (i == j || j == k || k == i) continue;
                if (array[i] + array[j] == array[k]) {
                    if (!flag[k]) ans ++;
                    flag[k] = true;
                }
            }
            
        }
    }
    cout << ans << endl;
    return 0;
}