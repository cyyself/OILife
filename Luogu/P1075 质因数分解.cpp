#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
bool judge(int num){
	for (int i=2;i<=sqrt(num);i++){
		if ((num / i) * i == num) return false;
	}
	return true;
}
int main(){
	int n;
	cin >> n;
	for (int i=2;i<=sqrt(n);i++){
		if (judge(i) && n / i * i == n && judge(n/i)) {
			cout << n/i << endl;
			return 0;
		}
	}
	return 0;
}