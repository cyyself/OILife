#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int n,m;
    int map[101][101] = {{0}};
    bool lei [101][101] = {{0}};
    cin >> n >> m;
    for (int i=0;i<n;i++){
        string s;
        cin >> s;
        for (int j=0;j<s.length();j++){
            if (s[j] == '*'){
                lei[i][j] = true;
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (lei[i][j] == true){
                map [i+1][j]++;
                map [i][j+1]++;
                map [i+1][j+1]++;
                if ( i > 0 ){
                    map [i-1][j]++;
                    map [i-1][j+1]++;
                }
                if ( j > 0){
                    map [i][j-1]++;
                    map [i+1][j-1]++;
                }
                if ( i > 0 && j > 0){
                    map [i-1][j-1]++;
                }
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (lei[i][j] == true){
                cout << "*";
            }
            else{
                cout << map[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}