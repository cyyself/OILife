#include <iostream>
using namespace std;
const string a[21] = {
	"zero",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine",
	"ten",
	"eleven",
	"twelve",
	"thirteen",
	"fourteen",
	"fifteen",
	"sixteen",
	"seventeen",
	"eighteen",
	"nineteen",
	"twenty"
};
const string b[11] = {
	"and",
	"ten",
	"twenty",
	"thirty",
	"forty",
	"fifty",
	"sixty",
	"seventy",
	"eighty",
	"ninety",
	"hundred"
};
string liangwei(int n) {
	if (n <= 20) {
		return a[n];
	}
	int shiwei = n / 10;
	if (n % 10 == 0) {
		return b[shiwei];
	}
	else {
		return b[shiwei] + " " + a[n%10];
	}
	
}
string sanwei(int n) {
	int baiwei = n / 100;
	int shiwei = (n / 10) % 10;
	int gewei = n % 10;
	string ret = a[baiwei] + " hundred";
	if (shiwei == 0 && gewei == 0) return ret;
	if (shiwei == 0) ret += " and";
	ret += " " + liangwei(shiwei * 10 + gewei);
	return ret;
}
string siwei(int n) {
	int qianwei = n / 1000;
	int baiwei = (n / 100) % 10;
	int shiwei = (n / 10) % 10;
	int gewei = n % 10;
	string ret = a[qianwei] + " thousand";
	if (baiwei == 0 && shiwei == 0 && gewei == 0) {
		return ret;
	}
	ret += " ";
	if (baiwei == 0) {
		ret += "and " + liangwei(shiwei * 10 + gewei);
	}
	else {
		ret += sanwei(baiwei * 100 + shiwei * 10 + gewei);
	}
	return ret;
}
int main() {
	int n;
	cin >> n;
	if (n < 100) {
		cout << liangwei(n) << endl;
		return 0;
	}
	if (n < 1000) {
		cout << sanwei(n) << endl;
		return 0;
	}
	if (n < 10000) {
		cout << siwei(n) << endl;
		return 0;
	}
	return 0;
}