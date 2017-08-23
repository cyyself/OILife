#include <iostream>
using namespace std;
int fibo(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fibo(n-1) + fibo(n-2);
}

int main() {
	int a,n,m,x;
	cin >> a >> n >> m >> x;
	if (x == 1 || x == 2) cout << a << endl;
	else {
		int b = (m-(fibo(n-3)+1)*a)/(fibo(n-2)-1);
		int up[25]={0};
		int down[25]={0};
		int tot[25]={0};
		up[1] = a;
		down[1] = 0;
		tot[1] = a;
		up[2] = b;
		down[2] = b;
		tot[2] = a;
		for (int i=3;i<=x;i++) {
			up[i] = up[i-1] + up[i-2];
			down[i] = up[i-1];
			tot[i] = tot[i-1] + up[i] - down[i];
		}
		cout << tot[x] << endl;
	}
	return 0;
}