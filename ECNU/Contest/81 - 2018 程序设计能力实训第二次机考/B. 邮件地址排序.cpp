#include <bits/stdc++.h>
using namespace std;
struct addr {
	string user,host;
	friend bool operator < (const addr &a,const addr &b) {
		if (a.host < b.host) return true;
		if (a.host == b.host && a.user > b.user) return true;
		return false;
	}
};
vector <addr> u;
int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		string tmp;
		cin >> tmp;
		bool userend = false;
		string user,host;
		for (int j=0;j<tmp.length();j++) {
			if (tmp[j] == '@') {
				userend = true;
				continue;
			}
			if (!userend) user += tmp[j];
			else host += tmp[j];
		}
		u.push_back((addr){user,host});
	}
	sort(u.begin(),u.end());
	for (vector<addr>::iterator it=u.begin();it != u.end();it++) {
		cout << it->user << '@' << it->host << endl;
	}
	return 0;
}