#include <cstdio>
int main() {
	int T,n;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		double x0,y0,x1,y1,x2,y2;
		double sx = 0;
		double sy = 0;
		double tots = 0;
		scanf("%lf%lf%lf%lf",&x0,&y0,&x1,&y1);
		for (int i=2;i<n;i++) {
			scanf("%lf%lf",&x2,&y2);
			double s = (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);
			s /= 2;
			sx += s*(x0+x1+x2)/3;
			sy += s*(y0+y1+y2)/3;
			tots += s;
			x1 = x2;
			y1 = y2;
		}
		printf("%0.2lf %0.2lf\n",sx/tots,sy/tots);
	}
	return 0;
}