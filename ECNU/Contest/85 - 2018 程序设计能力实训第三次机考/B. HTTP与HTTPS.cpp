#include <bits/stdc++.h>
using namespace std;
vector <string> url;
int main() {
	int n;
	cin >> n;
	for (int i=0;i<n;i++) {
		string tmp;
		cin >> tmp;
		if (tmp[4] != 's') url.push_back(tmp);
	}
	sort(url.begin(),url.end());
	for (vector<string>::iterator it=url.begin();it!=url.end();it++) cout << *it << endl;
	return 0;
}