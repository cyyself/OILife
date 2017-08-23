#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
bool map[64][64];
vector <int> a;
void draw(int node){
	queue <int> q;
	while(true){
		if (node / 5 > 0){
			q.push(node % 5);
			node = node / 5;
		}
		else{
			q.push(node);
			break;
		}
	}
	int sx,sy,ex,ey;
	sx = 0;
	sy = 0;
	ex = abs(n);
	ey = abs(n);
	while(!q.empty()){
		switch(q.front()){
			case 1:
				ex = (sx + ex) / 2;
				ey = (sy + ey) / 2;
				break;
			case 2:
				sx = (sx + ex) / 2;
				ey = (sy + ey) / 2;
				break;
			case 3:
				sy = (sy + ey) / 2;
				ex = (sx + ex) / 2;
				break;
			case 4:
				sx = (sx + ex) / 2;
				sy = (sy + ey) / 2;
				break;
		}
		q.pop();
	}
	for (int x=sx;x<ex;x++) for (int y=sy;y<ey;y++) map[x][y] = true;
}
bool check(int sx,int sy,int ex,int ey){
	for (int x = sx;x < ex;x++) for (int y = sy;y < ey;y++) if (!map[x][y]) return false;
	return true;
}
void DFS(int sx,int sy,int ex,int ey,int p,int layer){//p代表数字
	if (check(sx,sy,ex,ey)){
		a.push_back(p);
	}
	else{
		if (ex - sx > 1 && ey - sy > 1){
			DFS(sx,sy,(sx+ex)/2,(sy+ey)/2,1*pow(5,layer)+p,layer+1);
			DFS((sx+ex)/2,sy,ex,(sy+ey)/2,2*pow(5,layer)+p,layer+1);
			DFS(sx,(sy+ey)/2,(sx+ex)/2,ey,3*pow(5,layer)+p,layer+1);
			DFS((sx+ex)/2,(sy+ey)/2,ex,ey,4*pow(5,layer)+p,layer+1);
		}
	}
}
int main(){
	int cnt = 0;
	bool first = true;
	while (scanf("%d",&n) == 1 && n != 0){
		if (cnt>0) printf("\n");
		cnt++;
		memset(map,0,sizeof(map));
		a.clear();
		if (n < 0){
			int t;
			while(scanf("%d",&t) == 1 && t != -1){
				draw(t);
			}
			printf("Image %d\n",cnt);
			for (int y=0;y<abs(n);y++){
				for (int x=0;x<abs(n);x++){
					if (map[x][y] == true) printf("*");
					else printf(".");
				}
				printf("\n");
			}
		}
		else{
			for (int i=0;i<n;i++){//输入图
				string t;
				cin >> t;
				for (int j=0;j<n;j++){
					if (t[j]=='1') map[j][i] = true;
				}
			}
			DFS(0,0,n,n,0,0);
			sort(a.begin(),a.end());
			printf("Image %d\n",cnt);
			bool first = false;//行首
			if (a.size() > 0){
				for (int i=0;i<a.size();i++) {
					if ((i+1)%12==0 || i == a.size()-1) printf("%d\n",a[i]);
					else printf("%d ",a[i]);
				}
			}
			printf("Total number of black nodes = %ld\n",a.size());
		}
	}
	return 0;
}