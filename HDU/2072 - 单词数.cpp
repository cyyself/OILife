#include <bits/stdc++.h>
using namespace std;
string tmp;
int main() {
	while (getline(cin,tmp)) {
		if (tmp == "#") break;
		map <string,bool> mem;
		string word;
		for (int i=0;i<tmp.length();i++) {
			if (tmp[i] == ' ') {
				if (word != "") mem[word] = true;
				word = "";
			}
			else word += tmp[i];
		}
		if (word != "") mem[word] = true;
		printf("%lu\n",mem.size());
	}
	return 0;
}
