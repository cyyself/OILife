#include <bits/stdc++.h>
using namespace std;
map<string,string> dic;
string gen(int cur,int len) {
	string ret = "";
	while (cur) {
		if (cur & 1) ret = '1' + ret;
		else ret = '0' + ret;
		cur >>= 1;
	}
	while (ret.length() < len) ret = '0' + ret;
	return ret;
}
int prasebin(string s) {
	int ret = 0;
	for (unsigned long i=0;i<s.length();i++) {
		ret <<= 1;
		ret += s[i] - '0';
	}
	return ret;
}
int readlen() {
	int ret = 0;
	char c;
	int cnt = 0;
	while (cnt < 3) {
		c = getchar();
		if (c == '\n') continue;
		ret <<= 1;
		ret += c - '0';
		cnt ++;
	}
	return ret;
}
string read(int len) {
	string ret = "";
	char c;
	int cnt = 0;
	while (cnt < len) {
		c = getchar();
		if (c == '\n') continue;
		ret += c;
		cnt ++;
	}
	return ret;
}
int main() {
	while (true) {
		dic.clear();
		int cur = 0;
		int curlen = 1;
		char c = getchar();
		if (c == EOF) break;
		while (c != '\n') {
			dic[gen(cur,curlen)] = c;
			cur ++;
			if (__builtin_popcount(cur) == curlen) {
				cur = 0;
				curlen ++;
			}
			c = getchar();
		}
		while (true) {
			int len = readlen();
			if (len == 0) break;
			string breakpoint = "";
			for (int i=0;i<len;i++) breakpoint += '1';
			while (true) {
				string s = read(len);
				if (s == breakpoint) break;
				else {
					cout << dic[s];
				}
			}
		}
		getchar();//skip \n
		cout << endl;
	}
	return 0;
}
