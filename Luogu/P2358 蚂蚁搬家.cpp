/*
感谢题目讨论中题解的启发。
对于一个正方体，从上表面走到下表面只有可能经过1,2个面两种情况。
易证经过3个面肯定是有经过1个面或2个面的更优解的。
经过2个面又分为2种情况，分别是向下向左和向下向右。
而正方体旋转有4种情况，这样就变成4*(1+2)共12种情况。
其实，只需要写一个spin(旋转)函数，算出上下表面旋转后展开图的新位置，然后直接算即可。
注意旋转函数需要根据传入角度参数顺时针或逆时针旋转。
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
struct Pos {
	double x,y;
};
Pos u;//上表面
Pos d;//下表面
inline Pos spin(int dir,const Pos &in) {
	//旋转角度=dir*2/pi
	Pos out;
	switch (dir) {//按照顺时针顺序旋转，便于在后面直接取mod
		case 0:
			out.x = in.x;
			out.y = in.y;
			break;
		case 1:
			out.x = in.y;
			out.y = 1 - in.x;
			break;
		case 2:
			out.x = 1 - in.x;
			out.y = 1 - in.y;
			break;
		case 3:
			out.x = 1 - in.y;
			out.y = in.x;
			break;
	}
	return out;
}
inline double g(double x,double y) {//勾股定理
	return sqrt(x*x+y*y);
}
double work(int dir,int width) {
	/*
	width就是中间的宽度
		----
		|  |
		----
		|  |
		----
		|  |
		----
	width = 0
		----
		|  |
	-------
	|  |  |
	-------
	|  |
	----
	width = -1
	width = 1的情况以此类推
	*/
	Pos a;//上表面的旋转位置
	Pos b;//下表面的旋转位置
	double w;
	switch (width) {
		case 0:
			a = spin(dir,u);
			b = spin(dir,d);
			w = a.x - b.x;
			break;
		case 1:
			a = spin(dir,u);
			b = spin((dir+1)%4,d);//因为展开后上下表面旋转角度不一，可推出下表面的角度多旋转了90度
			w = 1 - a.x + b.x;
			break;
		case -1:
			a = spin(dir,u);
			b = spin((dir+3)%4,d);
			w = 1 - b.x + a.x;
			break;
	}
	//printf("dir=%d,width=%d,x=%lf,y=%lf\n",dir,width,w,a.y+1+b.y);
	return g(w,a.y+b.y+1);
}
int main() { 
	scanf("%lf%lf%lf%lf",&u.x,&u.y,&d.x,&d.y);
	u.x+=0.5;
	u.y+=0.5;
	d.x+=0.5;
	d.y+=0.5;
	//坐标+0.5，范围变为0~1，比较好计算 
	double ans = 1e9;//一个较大值当作INF
	for (int w=-1;w<=1;w++)
		for (int d=0;d<=3;d++)
			ans = min(ans,work(d,w));
	printf("%0.3lf\n",ans);
	return 0;
}