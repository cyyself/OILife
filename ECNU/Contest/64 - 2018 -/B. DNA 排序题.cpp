#include <bits/stdc++.h>
using namespace std;
struct DATA {
	string str;
	int cnt;
	friend bool operator < (const DATA &a,const DATA &b) {
		if (a.cnt < b.cnt) return true;
		if (a.cnt == b.cnt && a.str < b.str) return true;
		return false;
	}
};
vector <DATA> arr;
map <string,int> mem;
int main() {
	int n;
	cin >> n;
	while (n--) {
		string tmp;
		cin >> tmp;
		if (mem[tmp]) mem[tmp] ++;
		else {
			mem[tmp] = 1;
			arr.push_back((DATA){tmp,0});
		}
	}
	for (vector<DATA>::iterator it=arr.begin();it != arr.end();it++) {
		it->cnt = mem[it->str];
	}
	sort(arr.begin(),arr.end());
	for (vector<DATA>::iterator it=arr.begin();it != arr.end();it++) {
		cout << it->str << endl;
	}
	return 0;
}
