#include <cstdio>
using namespace std;
int pub[149][149]={0};
int d;
int check(int x,int y){
	int t = 0;
	int xmin = x - d;
	int xmax = x + d;
	int ymin = y - d;
	int ymax = y + d;
	if (xmax > 128) xmax = 128;
	if (ymax > 128) ymax = 128;
	if (xmin < 0) xmin = 0;
	if (ymin < 0) ymin = 0;
	for (int i=xmin;i<=xmax;i++) for (int j=ymin;j<=ymax;j++) t += pub[i][j];
	return t;
}
int main(){
	int n;
	scanf("%d%d",&d,&n);
	for (int i=0;i<n;i++){
		int x,y,k;
		scanf("%d%d%d",&x,&y,&k);
		pub[x][y] += k;
	}
	int max = 0;
	int ans = 0;
	for (int i=0;i<=128;i++){
		for (int j=0;j<=128;j++){
			int t = check(i,j);
			if (t == max) ans++;
			else if (t > max){
				max = t;
				ans = 1;
			}
		}
	}
	printf("%d %d",ans,max);
	return 0;
}