#include <bits/stdc++.h>
using namespace std;
int main() {
	int v1,v2,t,d;
	cin >> v1 >> v2 >> t >> d;
	int i = 1;
	int j = t;
	int ans = 0;
	for (int dec=1;dec<=t;dec++) {
		int sum = 0;
		int speed1 = v1;
		for (int i=1;i<dec;i++) {
			sum += speed1;
			speed1 += d;
		}
		int speed2 = v2;
		for (int i=t;i>dec;i--) {
			sum += speed2;
			speed2 += d;
		}
		if (abs(speed1 - speed2) <= d) ans = max(ans,sum+min(speed1,speed2));
	}
	cout << ans << endl;
	return 0;
}
