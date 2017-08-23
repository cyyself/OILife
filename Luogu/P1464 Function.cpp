#include <iostream>
#include <cstring>
using namespace std;
long long memory[21][21][21];
bool memoried[21][21][21];
long long w(long long a,long long b,long long c){
    long long result;
    if (a <= 0 || b<= 0 || c <= 0)
        return 1;
    if (a > 20 || b > 20 || c > 20) {
        return w(20,20,20);
    }
    if (memoried[a][b][c]){
        return memory[a][b][c];
    }
    if (a < b && b < c){
        result = w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    }
    else{
        result = w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
    }
    memory[a][b][c] = result;
    memoried[a][b][c] = true;
    return result;
}
int main(){
    memset(memoried,false,sizeof(memoried));
    while (true){
        long long a,b,c;
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;
        long long result = w(a,b,c);
        cout << "w(" << a << ", " << b << ", " << c <<") = " << result << endl;
    }
    return 0;
}