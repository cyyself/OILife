#include <bits/stdc++.h>
using namespace std;
map <string,bool> exist;
set <string> ans;
vector <string> s;
string t;
int main() {
	while (cin >> t) {
		s.push_back(t);
		exist[t] = true;
	}
	for (auto e:s) {
		for (int i=0;i<e.length()-1;i++) {
			if (exist[e.substr(0,i+1)] && exist[e.substr(i+1,e.length()-i-1)]) 
				ans.insert(e);
		}
	}
	for (auto a:ans) {
		cout << a << endl;
	}
	return 0;
}
