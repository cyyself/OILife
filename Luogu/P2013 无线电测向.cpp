#include <cstdio>
#include <cmath>
#include <iostream>
#include <map>
#define pi 3.1415926535897932384626
using namespace std;
map <string,int> num;
struct Pos {
	int x,y;
	Pos():x(-1),y(-1){}
}t[35];
int towercnt = 0;
struct xjs{
	double k;
	double b;
}l[2];
int main() {
	int n;
	cin >> n;
	for (int i=0;i<n;i++) {
		string buf;
		cin >> buf >> t[i].x >> t[i].y;
		num[buf] = i;
	}
	int boatdeg;
	cin >> boatdeg;
	int t1deg,t2deg;
	string t1,t2;
	cin >> t1 >> t1deg >> t2 >> t2deg;
	t1deg = -t1deg - boatdeg + 90;//不忍吐槽这脑残的角度
	t2deg = -t2deg - boatdeg + 90;
	l[0].k = tan((t1deg/180.0)*pi);
	l[1].k = tan((t2deg/180.0)*pi);
	l[0].b = t[num[t1]].y - t[num[t1]].x * l[0].k;
	l[1].b = t[num[t2]].y - t[num[t2]].x * l[1].k;
	//xk1+b1=xk2+b2
	if (l[0].k == l[1].k) printf("NO ANSWER\n");
	else {
		double x = (l[1].b-l[0].b) / (l[0].k-l[1].k);
		double y = l[0].k * x + l[0].b;
		printf("%0.2lf %0.2lf\n",x,y);
	}
	return 0;
}