#include <iostream>
using namespace std;
long long qpow(int a, int b,int mod){
	int ans = 1;
	while(b>0){
		if(b % 2)ans = ans * a % mod;
		b = b/2;
		a = a * a % mod;
	}
	return ans;
}
int main(){
	int n,m,k,x;
	cin >> n >> m >> k >> x;
	long long d = (qpow(10,k,n) * m + x)%n;
	cout << d << endl;
	return 0;
}