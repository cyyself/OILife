#include <bits/stdc++.h>
using std::map;
using std::cin;
using std::string;
map <string,int> type;
int main() {
	type["great!"] = 1;
	type["not bad"] = 1;
	type["cool"] = 1;
	type["don't think so"] = 1;
	type["don't touch me!"] = 1;
	type["don't even"] = 2;
	type["terrible"] = 2;
	type["worse"] = 2;
	type["are you serious?"] = 2;
	type["go die in a hole"] = 2;
	type["no way"] = 2;
	for (int i=9;i>=0;i--) {
		printf("%d\n",i);
		string buf;
		getline(cin,buf);
		if (type[buf] != 0) {
			if (type[buf] == 1) printf("normal\n");
			else printf("grumpy\n");
			return 0;
		}
	}
	//printf("grumpy\n");
	return 0;
}