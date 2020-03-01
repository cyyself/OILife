#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		double a,b,x,y;
		scanf("%lf%lf%lf%lf",&a,&b,&x,&y);
		double g = 9.8;
		double sin_1 = b / sqrt(a * a + b * b);//斜面倾角sin
		double cos_1 = a / sqrt(a * a + b * b);
		double a_s = g * sin_1;//小球沿斜面方向的加速度
		double x1 = x;//小球竖直落点x
		double y1 = x * (- b / a);//小球竖直落点y
		double l = sqrt(x1*x1 + y1*y1) + (y - y1) * sin_1;//小球运动总距离
		double tot = sqrt(2*l/a_s);//总时间
		double h_t = sqrt(2 * (y - y1) * cos_1 / (g * cos_1));//垂直方向运动的半周期
		printf("%d\n",(int)(1+(tot-h_t)/(h_t*2)));
	}
	return 0;
}
