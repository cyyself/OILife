#include <cstdio>
using namespace std;
int label[5][5]={
	{0,-1,1,1,-1},
	{1,0,-1,1,-1},
	{-1,1,0,-1,1},
	{-1,-1,1,0,1},
	{1,1,-1,-1,0}
};
int main(){
	int n,na,nb;
	int a[205];
	int b[205];
	scanf("%d%d%d",&n,&na,&nb);
	for (int i=0;i<na;i++) scanf("%d",&a[i]);
	for (int i=0;i<nb;i++) scanf("%d",&b[i]);
	int am = 0;
	int bm = 0;
	for (int i=0;i<n;i++){
		int as = a[i%na];
		int bs = b[i%nb];
		int s = label[as][bs];
		if (s == 1) am++;
		else if (s == -1) bm++;
	}
	printf("%d %d",am,bm);
}