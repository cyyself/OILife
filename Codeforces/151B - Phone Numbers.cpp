#include <bits/stdc++.h>
using namespace std;
int cnt[3];
vector <string> ans[3];
bool IsPizza(string a) {
	string tmp = "";
	for (int i=0;i<a.length();i++) if (a[i] >= '0' && a[i] <= '9') tmp += a[i];
	for (int i=1;i<tmp.length();i++) if (tmp[i] >= tmp[i-1]) return false;
	return true;
}
bool IsTaxi(string a) {
	string tmp = "";
	for (int i=0;i<a.length();i++) if (a[i] >= '0' && a[i] <= '9') tmp += a[i];
	for (int i=1;i<tmp.length();i++) if (tmp[i] != tmp[i-1]) return false;
	return true;
}
int main() {
	int n;
	cin >> n;
	while (n --) {
		int si;
		string name;
		cin >> si >> name;
		int tmp[3];
		memset(tmp,0,sizeof(tmp));
		while (si --) {
			string number;
			cin >> number;
			if (IsTaxi(number)) tmp[0] ++;
			else if (IsPizza(number)) tmp[1] ++;
			else tmp[2] ++;
		}
		for (int i=0;i<3;i++) {
			if (tmp[i] > cnt[i]) {
				cnt[i] = tmp[i];
				ans[i].clear();
				ans[i].push_back(name);
			}
			else {
				if (tmp[i] == cnt[i]) ans[i].push_back(name);
			}
		}
	}
	cout << "If you want to call a taxi, you should call: ";
	bool first = true;
	for (auto name:ans[0]) {
		if (!first) cout << ", ";
		cout << name;
		first = false;
	}
	cout << ".\n";
	cout << "If you want to order a pizza, you should call: ";
	first = true;
	for (auto name:ans[1]) {
		if (!first) cout << ", ";
		cout << name;
		first = false;
	}
	cout << ".\n";
	cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
	first = true;
	for (auto name:ans[2]) {
		if (!first) cout << ", ";
		cout << name;
		first = false;
	}
	cout << ".\n";
	return 0;
}
