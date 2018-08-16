#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <map>
using namespace std;
map <string,string> dic;
int main() {
	ios::sync_with_stdio(false);
	string tmp;
	while (getline(cin,tmp)) {
		if (tmp.length() == 0) break;
		string a;
		string b;
		int pos = 0;
		while (tmp[pos] != ' ') {
			a += tmp[pos];
			pos ++;
		}
		pos ++;
		while (pos < tmp.length()) {
			b += tmp[pos];
			pos ++;
		}
		dic[b] = a;
	}
	string w;
	while (getline(cin,w)) {
		if (dic[w] == "") cout << "eh" << endl;
		else cout << dic[w] << endl;
	}
	return 0;
}
