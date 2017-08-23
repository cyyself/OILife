#include <cstdio>
#include <cmath>
#include <queue>
#include <map> 
using namespace std;
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
int smap[3][3];
int goal[3][3] = {
	{1,2,3},
	{8,0,4},
	{7,6,5}
};
struct data{
	int map[3][3];
	int step;
	data(int _map[3][3],int step):step(step){for(int i=0;i<3;i++)for(int j=0;j<3;j++)map[i][j]=_map[i][j];}
	data():step(0){for(int i=0;i<3;i++)for(int j=0;j<3;j++)map[i][j]=0;}
	int getstatus(){
		int tot = 0;
		int n = 1;
		for (int i=2;i>=0;i--) for (int j=2;j>=0;j--){
			tot += map[i][j] * n;
			n = n * 10;
		}
	return tot;
	}
};
data swap(int map[3][3],int x1,int y1,int x2,int y2,int step){
	data t;
	for (int i=0;i<3;i++) for (int j=0;j<3;j++) t.map[i][j] = map[i][j];
	t.map[x2][y2] = map[x1][y1];
	t.map[x1][y1] = map[x2][y2];
	t.step = step;
	return t;
}
int solve(){
	map <int,int> step1;//到某一步的步数 
	map <int,int> step2;
	queue <data> q1;
	queue <data> q2;
	q1.push(data(smap,1));//step初始值为1，之后相加时再-2，这样就不用vis了 
	q2.push(data(goal,1));
	step1[data(smap,1).getstatus()] = 1;
	step2[data(goal,1).getstatus()] = 1;
	while(!q1.empty() && !q2.empty()){
		if (!q1.empty()){
			data q1now = q1.front();
			q1.pop();
			if (step2[q1now.getstatus()] != 0) return step2[q1now.getstatus()] + q1now.step - 2;
			for (int i=0;i<3;i++) for (int j=0;j<3;j++){
				if (q1now.map[i][j] == 0) {
					for (int k=0;k<4;k++){
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (nx < 0 || ny < 0 || nx > 2 || ny > 2) continue;
						if (step1[swap(q1now.map,i,j,nx,ny,q1now.step+1).getstatus()] == 0)
						{
							q1.push(swap(q1now.map,i,j,nx,ny,q1now.step+1));
							step1[swap(q1now.map,i,j,nx,ny,q1now.step+1).getstatus()] = q1now.step+1;
						}
					}
				}
			}
		}
		if (!q2.empty()){
			data q2now = q2.front();
			q2.pop();
			if (step1[q2now.getstatus()] != 0) return step1[q2now.getstatus()] + q2now.step - 2;
			for (int i=0;i<3;i++) for (int j=0;j<3;j++){
				if (q2now.map[i][j] == 0) {
					for (int k=0;k<4;k++){
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (nx < 0 || ny < 0 || nx > 2 || ny > 2) continue;
						if (step2[swap(q2now.map,i,j,nx,ny,q2now.step+1).getstatus()] == 0){
							q2.push(swap(q2now.map,i,j,nx,ny,q2now.step+1));
							step2[swap(q2now.map,i,j,nx,ny,q2now.step+1).getstatus()] = q2now.step+1;
						}
					}
				}
			}
		}
	}
	return -1;
}
int main(){
	for (int i=0;i<3;i++) for (int j=0;j<3;j++){
		char c;
		scanf("%c",&c);
		smap[i][j] = c - 48;
	}
	printf("%d",solve());
	return 0;
}