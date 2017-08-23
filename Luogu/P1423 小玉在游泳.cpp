#include <cstdio>
int main() {
	double goal;
	scanf("%lf",&goal);
	int step = 0;
	double d = 2;
	double cur = 0;
	while (cur < goal) {
		cur += d;
		d = d * 0.98;
		step++;
	}
	printf("%d\n",step);
	return 0;
}