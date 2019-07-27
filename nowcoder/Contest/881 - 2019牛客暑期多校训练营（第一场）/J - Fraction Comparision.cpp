#include <bits/stdc++.h>
using namespace std;
int main() {
	long long _a,_b,_x,_y;
	while (cin >> _a >> _b >> _x >> _y) {
		__int128 a = _a,b = _b,x = _x,y = _y;
		__int128 diff = x * b - y * a;
		if (diff == 0) printf("=\n");
		else if (diff < 0) printf(">\n");
		else printf("<\n");
	}
	return 0;
}