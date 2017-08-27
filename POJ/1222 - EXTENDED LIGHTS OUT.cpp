#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using std::swap;
int n = 30;
int ma[35][35];
int pos[5][6];
void prepare() {
	for (int i=0;i<5;i++)
		for (int j=0;j<6;j++) pos[i][j] = i * 6 + j;
}
inline int getpos(int x,int y) {//这个函数仅仅为了让代码高亮好看一点
	return pos[x][y];
}
void gauss() {
	for (int i=0;i<n;i++) {
		int k = i;
		for (int j=i+1;j<n;j++) if (abs(ma[j][i]) > abs(ma[k][i])) k = j;
		int now = ma[k][i];
		if (k != i) for (int j=i;j<=n;j++) swap(ma[i][j],ma[k][j]);
		//for (int j=i;j<=n;j++) ma[i][j] /= now;
		for (int k=0;k<n;k++) if (k != i && ma[k][i]) {
			for (int j=i;j<=n;j++) ma[k][j] = ma[k][j] ^ ma[i][j];
		}
	}
}
int main() {
	prepare();
	int T;
	scanf("%d",&T);
	for (int t=1;t<=T;t++) {
		memset(ma,0,sizeof(ma));
		for (int i=0;i<5;i++)
			for (int j=0;j<6;j++) {
				int curpos = getpos(i,j);
				ma[curpos][curpos] = 1;//d(0,0)
				if (i < 4) ma[getpos(i+1,j)][curpos] = 1;//d(+1,0)
				if (i > 0) ma[getpos(i-1,j)][curpos] = 1;//d(-1,0)
				if (j < 5) ma[getpos(i,j+1)][curpos] = 1;//d(0,+1)
				if (j > 0) ma[getpos(i,j-1)][curpos] = 1;//d(0,-1)
			}
		for (int i=0;i<5;i++) 
			for (int j=0;j<6;j++) scanf("%d",&ma[getpos(i,j)][30]);
		gauss();
		printf("PUZZLE #%d\n",t);
		for (int i=0;i<5;i++){
			for (int j=0;j<6;j++) printf("%d ",ma[getpos(i,j)][30]);
			printf("\n");
		}
	}
	return 0;
}
