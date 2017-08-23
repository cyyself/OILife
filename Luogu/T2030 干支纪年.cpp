#include <iostream>
using namespace std;
int main() {
	const string a[10] = {"癸","甲","乙","丙","丁","戊","己","庚","辛","壬"};
	const string b[12] = {"亥","子","丑","寅","卯","辰","巳","午","未","申","酉","戌"};
	int year;
	while(cin >> year) cout << a[(year+7)%10] << b[(year+9)%12] << endl;
	return 0;
}