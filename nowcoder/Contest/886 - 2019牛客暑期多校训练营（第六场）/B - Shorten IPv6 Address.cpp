#include <bits/stdc++.h>
using namespace std;
char s[150];
int num[10],suf[10];
string outx(int x) {
	char buf[10];
	sprintf(buf,"%x",x);
	return buf;
}
string cut(int pos) {
	string ret = "";
	for (int i=0;i<pos;i++) {
		ret += outx(num[i]);
		if (i != pos - 1) ret += ":";
	}
	ret += "::";
	for (int i=pos+suf[pos];i<8;i++) {
		ret += outx(num[i]);
		if (i != 7) ret += ":";
	}
	return ret;
}
string nocut() {
	string ret = "";
	for (int i=0;i<8;i++) {
		ret += outx(num[i]);
		if (i != 7) ret += ":";
	}
	return ret;
}
bool cmp(string a,string b) {
	return a.length() < b.length() || (a.length() == b.length() && a < b);
}
int main() {
	int T;
	cin >> T;
	for (int cas=1;cas<=T;cas++) {
		cin >> s;
		memset(num,0,sizeof(num));
		memset(suf,0,sizeof(suf));
		for (int i=0;i<8;i++) {
			for (int j=i*16;j<(i+1)*16;j++) {
				num[i] *= 2;
				num[i] += s[j] - '0';
			}
		}
		int pos = -1;
		for (int j=7;j>=0;j--) {
			if (num[j] == 0) {
				suf[j] = suf[j+1] + 1;
			}
			if (suf[j] >= 2 && (pos == -1 || suf[j] > suf[pos])) pos = j;
		}
		vector <string> ans;
		ans.push_back(nocut());
		for (int i=0;i<8;i++) if (suf[i] >= 2) ans.push_back(cut(i));
		sort(ans.begin(),ans.end(),cmp);
		cout << "Case #" << cas << ": " << ans[0] << "\n";
	}
	return 0;
}
