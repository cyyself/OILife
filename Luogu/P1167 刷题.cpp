#include <iostream>
#include <algorithm>
using namespace std;
struct date {
	int year,month,day;
	date(int y,int m,int d):year(y),month(m),day(d){}
	date():year(0),month(0),day(0){}
};
bool judge(int year) {//判断闰年，四年一闰，百年不闰，四百年再闰。
	if (year % 400 == 0) return true;
	if (year % 100 == 0) return false;
	if (year % 4 == 0) return true;
	return false;
}
long long diffyears(int a,int b) {//输入两个年份，返回之间的天数
	long long t = 0;
	for (int i=a;i<b;i++) {
		if (judge(i)) t+= 366;
		else t+= 365;
	}
	return t;
}
int getdays(int month,bool runnian) {
	const int d[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if (month == 2 && runnian) return 29;
	else return d[month - 1];
}
long long diffdays(date a,date b) {//输入两个日期，返回之间的天数
	long long ta = 0;
	long long tb = 0;
	for (int i=1;i<a.month;i++){
		ta += getdays(i,judge(a.year));
	}
	ta += a.day;
	for (int i=1;i<b.month;i++){
		tb += getdays(i,judge(b.year));
	}
	tb += b.day;
	long long d = diffyears(a.year,b.year) + tb - ta;
	return d;
}
int difftime(int ha,int ma,int hb,int mb) {
	int a = 60 * ha + ma;
	int b = 60 * hb + mb;
	return b-a;
}
int toint(string a) {
	int t = 0;
	int n = 1;
	int p = 0;
	if (a[0] == '-') {
		n = -1;
		p = 1;
	}
	for (int i=a.length()-1;i>=p;i--) {
		t += (a[i]-48) * n;
		n *= 10;
	}
	return t;
}
bool comp(int a,int b) {
	if (a < b) return true;
	return false;
}
int main(){
	int N;
	cin >> N;
	int t[5005];
	for (int i=0;i<N;i++) cin >> t[i];
	sort(t,t+N,comp);
	string t1,t2;
	cin >> t1 >> t2;
	date a,b;
	a.year = toint(t1.substr(0,4));
	a.month = toint(t1.substr(5,2));
	a.day = toint(t1.substr(8,2));
	b.year = toint(t2.substr(0,4));
	b.month = toint(t2.substr(5,2));
	b.day = toint(t2.substr(8,2));
	long long d = diffdays(a,b) * 1440 + difftime(toint(t1.substr(11,2)),toint(t1.substr(14,2)),toint(t2.substr(11,2)),toint(t2.substr(14,2)));
	int cnt = 0;
	for (int i=0;i<N;i++) {
		if (d - t[i] >= 0) {
			d -= t[i];
			cnt ++;
		}
	}
	cout << cnt << endl;
	return 0;
}