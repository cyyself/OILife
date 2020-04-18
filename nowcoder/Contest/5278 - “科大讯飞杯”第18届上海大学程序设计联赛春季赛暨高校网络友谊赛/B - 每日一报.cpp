#include <bits/stdc++.h>
using namespace std;
struct DATA {
	string date,temp,id;
	friend bool operator < (const DATA &a,const DATA &b) {
		if (a.date != b.date) return a.date > b.date;
		else if (a.temp != b.temp) return a.temp > b.temp;
		else return a.id < b.id;
	}
};
int main() {
	int n;
	scanf("%d",&n);
	vector <DATA> arr;
	for (int i=0;i<n;i++) {
		DATA x;
		cin >> x.date >> x.id >> x.temp;
		if (x.temp >= "38.0") arr.push_back(x);
	}
	printf("%d\n",arr.size());
	sort(arr.begin(),arr.end());
	for (auto x:arr) cout << x.date << " " << x.id << " " << x.temp << "\n";
	return 0;
}
