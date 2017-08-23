#include <iostream>
using namespace std;
int main(){
	int n,x;
	cin >> n >> x;
	int count = 0;
	for (int i=1;i<=n;i++){
		int t = i;
		while(t != 0){
			if (t % 10 == x) count ++;
			t /= 10;
		} 
	}
	cout << count << endl;
}