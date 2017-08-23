#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#define INF 2147483647
struct Pos {
	int x;
	int y;
};
Pos area[155];
double g[155][155];
double max(double a, double b) {
	if (a > b) return a;
	return b;
}
double min(double a, double b) {
	if (a < b) return a;
	return b;
}
double CalcDist(int i, int j) {//勾股定理
	return sqrt( pow(area[i].x-area[j].x,2) + pow(area[i].y-area[j].y,2) );
}
int main() {
	int N;
	scanf("%d",&N);
	for (int i=1;i<=N;i++) scanf("%d%d",&area[i].x,&area[i].y);
	for (int i=1;i<=N;i++) for (int j=1;j<=N;j++) {
		char c;
		scanf(" %c",&c);
		if (c == '1') g[i][j] = CalcDist(i,j);
		else if (i != j) g[i][j] = INF;
		else g[i][j] = 0;
	}
	for (int k=1;k<=N;k++)
		for (int i=1;i<=N;i++)
			for (int j=1;j<=N;j++) if (i != j && j != k && k != i) g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
	double m[155] = {0};//最远直径
	for (int i=1;i<=N;i++) 
		for (int j=1;j<=N;j++) {
			if (g[i][j] != INF) m[i] = max(m[i],g[i][j]);
		}
	double ans = INF;
	for (int i=1;i<=N;i++) for (int j=1;j<=N;j++) {
		if (g[i][j] == INF) {
			ans = min(ans,m[i]+m[j]+CalcDist(i,j));
		}
	}
	for (int i=1;i<=N;i++) ans=max(ans,m[i]);//如果有一个牧场比两个牧场连起来更大，那么输出它
	printf("%.6lf\n",ans);
	return 0;
}