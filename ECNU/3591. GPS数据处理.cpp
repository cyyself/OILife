#include <bits/stdc++.h>
using namespace std;
int to10(char c) {
	if (c <= '9') return c - '0';
	if (c <= 'Z') return 10 + c - 'A';
	return 10 + c - 'a';
}
bool getstatus(string s) {
	int len = s.length();
	int i = 7;
	for (i=7;i<len;i++) {
		if (s[i] == ',') break;
	}
	return s[i+1] == 'A';
}
int main() {
	string tmp;
	int ans_h,ans_m,ans_s;
	while (1) {
		getline(cin,tmp);
		if (tmp == "END") break;
		if (tmp.substr(0,6) != "$GPRMC") continue;
		if (!getstatus(tmp)) continue;
		int h = (tmp[7]-'0') * 10 + tmp[8]-'0';
		h = (h + 8) % 24;
		int m = (tmp[9]-'0') * 10 + tmp[10]-'0';
		int s = (tmp[11]-'0') * 10 + tmp[12]-'0';
		char checksum = 0;
		for (int i=1;i<tmp.length() && tmp[i] != '*';i++) checksum ^= tmp[i];
		//printf("checksum=%x\n",checksum);//debug
		if (checksum == to10(tmp[tmp.length()-2]) * 16 + to10(tmp[tmp.length()-1])) {
			ans_h = h;
			ans_m = m;
			ans_s = s;
		}
	}
	printf("%02d:%02d:%02d\n",ans_h,ans_m,ans_s);
	return 0;
}
