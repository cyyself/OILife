#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
bool IsCharacter(char c) {
	if (c >= 'a' && c <= 'z') return true;
	return false;
}
bool IsNumber(char c) {
	if (c >= '0' && c <= '9') return true;
	return false;
}
void decode(string s,int &xishu,int &changshu,char &weizhishu){
	int p = 0;
	while (p < s.length()) {
		//读取符号
		bool sign = true;
		if (s[p] == '-') sign = false;
		p++;
		//读取数字
		stack <int> t;
		while (IsNumber(s[p])) {
			t.push(s[p]-48);
			p++;
		}
		int n = 1;
		int nt = 0;
		while(!t.empty()) {
			nt += t.top() * n;
			n *= 10;
			t.pop();
		}
		if (!sign) nt = -nt;
		//判断是一次项还是常数项
		if (IsCharacter(s[p])) {
			if (nt == 0) {
				nt = 1;
				if (!sign) nt = -nt;
			}
			weizhishu = s[p];
			xishu += nt;
			p++;
		}
		else {
			changshu += nt;
		}
	}
}
int main() {
	string s;
	cin >> s;
	string a = s.substr(0,s.find("="));
	string b = s.substr(s.find("=")+1);
	if (a[0] != '-') a = '+' + a;
	if (b[0] != '-') b = '+' + b;
	int an = 0;
	int ax = 0;
	int bn = 0;
	int bx = 0;
	char weizhishu;
	decode(a,ax,an,weizhishu);
	decode(b,bx,bn,weizhishu);
	ax -= bx;
	bn -= an;
	double result = (double) bn / ax;
	if (result == -0) result = 0;
	printf("%c=%.3f\n",weizhishu,result);
	return 0;
}