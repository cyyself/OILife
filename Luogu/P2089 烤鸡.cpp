#include <iostream>
#include <vector>
using namespace std;
struct as{
	int a[10];
};
vector <as> a;
int n;
int t[10];
void genans(int l) {
	if (l == 10) {
		//check then output answer
		int m = 0;
		for (int i=0;i<10;i++) m += t[i];
		if (m == n) {
			as tas;
			for (int i=0;i<10;i++)tas.a[i] = t[i];
			a.push_back(tas);
		}
	}
	else {
		t[l] = 1;
		genans(l+1);
		t[l] = 2;
		genans(l+1);
		t[l] = 3;
		genans(l+1);
	}
}
int main() {
	cin >> n;
	genans(0);
	cout << a.size() << endl;
	for (int i=0;i<a.size();i++) {
		for (int j=0;j<10;j++) cout << a[i].a[j] << " ";
		cout << endl;
	}
}