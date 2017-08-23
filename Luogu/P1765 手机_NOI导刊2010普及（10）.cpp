#include <iostream>
#include <map>
using namespace std;
int main() {
	map<char,int> mem;
	mem['a'] = 1;
	mem['b'] = 2;
	mem['c'] = 3;
	mem['d'] = 1;
	mem['e'] = 2;
	mem['f'] = 3;
	mem['g'] = 1;
	mem['h'] = 2;
	mem['i'] = 3;
	mem['j'] = 1;
	mem['k'] = 2;
	mem['l'] = 3;
	mem['m'] = 1;
	mem['n'] = 2;
	mem['o'] = 3;
	mem['p'] = 1;
	mem['q'] = 2;
	mem['r'] = 3;
	mem['s'] = 4;
	mem['t'] = 1;
	mem['u'] = 2;
	mem['v'] = 3;
	mem['w'] = 1;
	mem['x'] = 2;
	mem['y'] = 3;
	mem['z'] = 4;
	mem[' '] = 1;
	string s;
	getline(cin,s);
	int ans = 0;
	for (int i=0;i<s.length();i++) {
		ans += mem[s[i]];
	}
	cout << ans << endl;
	return 0;
}