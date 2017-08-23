#include <iostream>
#include <map>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;
map <string,int> mem;
void init() {
	mem["one"] = 1;
	mem["two"] = 2;
	mem["three"] = 3;
	mem["four"] = 4;
	mem["five"] = 5;
	mem["six"] = 6;
	mem["seven"] = 7;
	mem["eight"] = 8;
	mem["nine"] = 9;
	mem["ten"] = 10;
	mem["eleven"] = 11;
	mem["twelve"] = 12;
	mem["thirteen"] = 13;
	mem["fourteen"] = 14;
	mem["fifteen"] = 15;
	mem["sixteen"] = 16;
	mem["seventeen"] = 17;
	mem["eighteen"] = 18;
	mem["nineteen"] = 19;
	mem["twenty"] = 20;
	mem["a"] = 1;
	mem["both"] = 2;
	mem["another"] = 1;
	mem["first"] = 1;
	mem["second"] = 2;
	mem["third"] = 3;
}
char a[6][3];
long long MIN = 0x7fffffffffffffff;
bool used[6] = {false};
string inttostr(int x) {
	char tmp[16];
	sprintf(tmp,"%d",x);
	string t;
	int len = strlen(tmp);
	for (int i=0;i<len;i++) {
		t += tmp[i];
	}
	return t;
}
long long strtoll(string s) {
	long long tmp = 0;
	for (int i=0;i<s.length();i++) {
		if (s[i] < '0' || s[i] > '9') continue;
		tmp *= 10;
		tmp += (long long)s[i] - '0';
	}
	return tmp;
}

void DFS(int depth,string now) {
	if (depth == 0) {
		long long x = strtoll(now);
		if (x < MIN) MIN = x;
		//if (x < 0) cout << "error:" << now << "->" << x << endl;
	}
	else {
		for (int i=0;i<6;i++) 
			if (!used[i]) {
				used[i] = true;
				DFS(depth-1,now + a[i][0] + a[i][1]);
				used[i] = false;
			}
	}
}

int main() {
	init();
	for (int i=0;i<6;i++) {
		string t1;
		cin >> t1;
		int t2 = mem[t1];
		t2 = (t2 * t2) % 100;
		sprintf(a[i],"%02d",t2);
	}
	DFS(6,"");
	cout << MIN << endl;
	return 0;
}