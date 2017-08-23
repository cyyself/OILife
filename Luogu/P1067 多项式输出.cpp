#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	bool first = true;
	for (int i=n;i>=0;i--){
		int xishu;
		cin >> xishu;
		if (xishu != 0){
			if (xishu > 0){
				if (!first) cout << "+";
				if (xishu != 1 || i == 0) cout << xishu;
			}
			else {//xishu < 0
				if (xishu == -1 && i != 0) cout << "-";
				else cout << xishu;
			}
			if (i > 0) cout << "x";
			if (i > 1) cout << "^" << i;
			first = false;
		}
	}
}