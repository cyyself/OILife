#include <iostream>
#include <set>
using namespace std;
set <string> a;
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i=0;i<n;i++) {
		string buff;
		cin >> buff;
		a.insert(buff);
	}
	cout << a.size() << endl;
	return 0;
}