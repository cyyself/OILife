#include <bits/stdc++.h>
using namespace std;
struct Pos {
	long long x,y;
}p[3];
/*
double rand_double(double x,double y) {
	double r = (double)rand() / 2147483647;
	return x + (y - x) * r;
}
*/
inline long long cp(const Pos &e,const Pos &c,const Pos &s) {
	return (e.x - s.x) * (c.y - s.y) - (c.x - s.x) * (e.y - s.y);
}
int main() {
	srand(time(NULL));
	while (scanf("%lld%lld%lld%lld%lld%lld",&p[0].x,&p[0].y,&p[1].x,&p[1].y,&p[2].x,&p[2].y) == 6) {
		/*
		double l = 1e9,r = -1e9,u = -1e9, d = 1e9;
		for (int i=0;i<3;i++) {
			l = min(l,p[i].x);
			r = max(r,p[i].x);
			u = max(u,p[i].y);
			d = min(d,p[i].y);
		}
		*/
		long long S = abs(cp(p[0],p[1],p[2]));
		//cout << "S=" << S << endl;
		/*
		if (S < eps) {
			printf("0\n");
		}
		else */printf("%lld\n",S*11);
		/*
		double sum = 0;
		int cnt = 0;
		for (int i=0;i<10000000;i++) {
			double x = rand_double(l,r);
			double y = rand_double(d,u);
			Pos cur = {x,y};
			double s[3] = {abs(cp(p[0],p[1],cur))/2,abs(cp(p[1],p[2],cur))/2,abs(cp(p[2],p[0],cur))/2};
			if (abs(s[0] + s[1] + s[2] - S) < eps) {
				cnt ++;
				double SS=max(s[0],max(s[1],s[2]));
				if(cnt==1)
					sum=SS;
				else sum=((cnt-1)*sum+SS)/(cnt); 
			}
		}
		sum *= 36;
		cout << sum << endl;
		*/
	}
	return 0;
}