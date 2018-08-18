#include <bits/stdc++.h>
using namespace std;
string read() {
	string ret = "";
	char c = getchar();
	while (!(c >= '0' && c <= '9')) {
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		ret += c;
		c = getchar();
	}
	return ret;
}
map <string,int> exist;
string getthisyear(int year) {
	int tmp = year;
	string cur = "";
	while (exist[cur]) {
		cur = char('0'+year%10) + cur;
		year /= 10;
	}
	exist[cur] = tmp;
	return cur;
}
string gen1(int len) {
	string ret = "";
	while (len --) ret += '1';
	return ret;
}
int main() {
	exist[""] = -1;
	for (int i=1989;i<=20000;i++) getthisyear(i);//打表
	int n;
	scanf("%d",&n);
	while (n--) {
		string year = read();
		if (exist[year] != 0) cout << exist[year] << endl;
		else {
			string up = gen1(year.length()-4) + "3098";
			if (year <= up) cout << 1;
			cout << year << endl;
		}
	}
	return 0;
}
