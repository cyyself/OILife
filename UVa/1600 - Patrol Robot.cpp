#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int map[21][21];
int k;
int n,m;
const int nx[] = {0,1,0,-1};
const int ny[] = {1,0,-1,0};
struct robot{
	int x;//location
	int y;
	int s;//step
	int k;//cross
};
robot Newrobot(int x,int y,int s, int k){
	robot t;
	t.x = x;
	t.y = y;
	t.s = s;
	t.k = k;
	return t;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&m,&n,&k);
		memset(map,0,sizeof(map));
		int ans = -1;
		for (int i=0;i<m;i++) for (int j=0;j<n;j++) scanf("%d",&map[i][j]);
		queue <robot> q;
		q.push(Newrobot(0,0,0,0));
		map[0][0] = 2;
		while(!q.empty()){
			robot now = q.front();
			q.pop();
			if (now.x == m-1 && now.y == n-1) ans = now.s;
			for (int i=0;i<4;i++){
				int x = now.x + nx[i];
				int y = now.y + ny[i];
				if (x < 0 || y < 0 || x >= m || y >= n) continue;
				if (map[x][y] == 0) {
					map[now.x][now.y] = 2;
					q.push(Newrobot(x,y,now.s+1,0));
				}
				if (map[x][y] == 1 && now.k + 1 <= k) {
					map[now.x][now.y] = 2;
					q.push(Newrobot(x,y,now.s+1,now.k+1));
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
