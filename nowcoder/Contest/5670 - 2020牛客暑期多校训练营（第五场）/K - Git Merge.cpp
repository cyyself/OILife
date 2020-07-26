#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
const int maxn = 4005;
const int mo1 = 19260817, mo2 = 998244353;
int n,m;
void debug() {}
int calh(const string &s,long long mo) {
	long long res = 0;
	long long base = 233;
	for (auto c:s) {
		res += c * base;
		res %= mo;
		base *= 233;
		base %= mo;
	}
	return res;
}
int h[2][maxn][2];
vector <string> s[2];
bool eq(int i,int j) {
	return h[0][i][0] == h[1][j][0] && h[0][i][1] == h[1][j][1];
}
short f[maxn][maxn][3];//0:直接放,1:用一个,2:用两个
short pre[maxn][maxn][3];//1:i-1,2:j-1,3:i-1,j-1，高8位放k，这题又卡时间又卡内存
void trans(int i1,int j1,int k1,int i2,int j2,int k2) {
	if (i1 < 0 || j1 < 0) return;
	int lineadd = i2 - i1 + j2 - j1;
	if (lineadd == 2) {
		if (k2 == 0 && eq(i2-1,j2-1)) lineadd --;
		else return;
	}
	else {
		if (k1 == 0) {
			if (k2 == 1) lineadd += 2;
			else return;
		}
		else if (k1 == 1) {
			if (k2 == 2) lineadd += 1;
			else {
				int src = j2 - j1;
				int lastsrc = (pre[i1][j1][k1] & 2) >> 1;
				if (src != lastsrc) return;
			}
		}
		else if (k1 == 2) {
			if (k2 == 1) return;
		}
	}
	if (f[i1][j1][k1] + lineadd < f[i2][j2][k2]) {
		f[i2][j2][k2] = f[i1][j1][k1] + lineadd;
		short preval = 0;
		if (i1 < i2) preval |= 1;
		if (j1 < j2) preval |= 2;
		preval |= k1 << 8;
		pre[i2][j2][k2] = preval;
	}
}
void outbuf(vector <int> buf[2]) {
	if (buf[0].size()) {
		cout << "#ifdef branch1\n";
		for (auto x:buf[0]) cout << s[0][x] << "\n";
		if (buf[1].size()) {
			cout << "#else\n";
			for (auto x:buf[1]) cout << s[1][x] << "\n";
		}
		cout << "#endif\n";
	}
	else if (buf[1].size()) {
		cout << "#ifdef branch2\n";
		for (auto x:buf[1]) cout << s[1][x] << "\n";
		cout << "#endif\n";
	}
}
void output() {
	int i = n, j = m, k = 0;
	for (int kk=1;kk<3;kk++) if (f[i][j][kk] < f[i][j][k]) k = kk;
	vector <tuple<int,int,int> > stat;
	while (i || j) {
		stat.push_back(make_tuple(i,j,k));
		int ii = i;
		int jj = j;
		int kk = pre[i][j][k] >> 8;
		if (pre[i][j][k] & 1) ii --;
		if (pre[i][j][k] & 2) jj --;
		i = ii;
		j = jj;
		k = kk;
	}
	reverse(stat.begin(),stat.end());
	i = 0;
	j = 0;
	k = 0;
	vector <int> buf[2];
	debug();
	for (auto x:stat) {
		int ii = get<0>(x),jj = get<1>(x),kk = get<2>(x);
		int src = jj - j;
		if (kk != k) {
			if (kk == 0) {
				if (ii - i && jj - j) {
					//清空buf
					outbuf(buf);
					buf[0].clear();
					buf[1].clear();
					cout << s[1][jj-1] << "\n";
				}
				else {
					//加入这个，然后清空buf
					buf[src].push_back(src?jj-1:ii-1);
					outbuf(buf);
					buf[0].clear();
					buf[1].clear();
				}
			}
			else {
				buf[src].push_back(src?jj-1:ii-1);
			}
		}
		else {
			if (k == 0) cout << s[1][jj-1] << "\n";
			else {
				buf[src].push_back(src?jj-1:ii-1);
			}
		}
		i = ii;
		j = jj;
		k = kk;
		//tie(i,j,k) = tie(ii,jj,kk);
	}
	if (!buf[0].size() || !buf[1].size()) outbuf(buf);
}
int main() {
	ios::sync_with_stdio(false);
	int stat = 3;
	while (true) {
		string tmp;
		if (!getline(cin,tmp)) break;
		if (tmp == "<<<<<<< branch1") stat = 1;
		else if (tmp == "=======") stat = 2;
		else if (tmp == ">>>>>>> branch2") stat = 3;
		else {
			if (stat & 1) s[0].push_back(tmp);
			if (stat & 2) s[1].push_back(tmp);
		}
	}
	n = s[0].size();
	m = s[1].size();
	for (int i=0;i<2;i++) {
		for (int j=0;j<s[i].size();j++) {
			h[i][j][0] = calh(s[i][j],mo1);
			h[i][j][1] = calh(s[i][j],mo2);
		}
	}
	for (int i=0;i<=n;i++) for (int j=0;j<=m;j++) for (int k=0;k<3;k++) f[i][j][k] = 0x3f3f3f3f;
	f[0][0][0] = 0;
	for (int i=0;i<=n;i++) for (int j=0;j<=m;j++) if (i || j) {
		trans(i-1,j-1,0,i,j,0);
		trans(i-1,j-1,1,i,j,0);
		trans(i-1,j-1,2,i,j,0);
		trans(i-1,j,0,i,j,1);
		trans(i-1,j,1,i,j,0);
		trans(i-1,j,1,i,j,1);
		trans(i-1,j,1,i,j,2);
		trans(i-1,j,2,i,j,0);
		trans(i-1,j,2,i,j,2);
		trans(i,j-1,0,i,j,1);
		trans(i,j-1,1,i,j,0);
		trans(i,j-1,1,i,j,1);
		trans(i,j-1,1,i,j,2);
		trans(i,j-1,2,i,j,0);
		trans(i,j-1,2,i,j,2);
	}
	output();
	//printf("%lld\n",min(f[n][m][0],min(f[n][m][1],f[n][m][2])));
	return 0;
}
