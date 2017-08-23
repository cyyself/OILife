#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n;
	cin >> n;
	int lianxu = 0;
	int yilou = 0;
	int score = 0;
	bool begin = false;
	for (int i=1;i<=n;i++) {
		int t;
		cin >> t;
		if (t == 1) {
			//打卡！
			if (yilou != 0) {
				lianxu -= pow(2,yilou - 1);
				if (lianxu < 0) lianxu = 0;
			}
			lianxu ++;
			if (lianxu >= 1) score ++;
			if (lianxu >= 3) score ++;
			if (lianxu >= 7) score ++;
			if (lianxu >= 30) score ++;
			if (lianxu >= 120) score ++;
			if (lianxu >= 365) score ++;
			yilou = 0;
		}
		else yilou ++;
	}
	cout << score << endl;
	return 0;
}
//http://www.luogu.org/index/ajax_punch