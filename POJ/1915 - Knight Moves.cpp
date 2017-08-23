#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>
//#include <map>

using namespace std;

const int dx[8] = {-2,-2,-1,-1,1,1,2,2};
const int dy[8] = {-1,1,2,-2,-2,2,-1,1};

struct Pos{
	int x,y;
	int step;
	Pos():x(0),y(0),step(0){}
	Pos(int _x,int _y,int _step):x(_x),y(_y),step(_step){}
};

int l;
Pos startp;
Pos endp;
int solve(){
	queue <Pos> q1;
	queue <Pos> q2;
	//map <int,int> m1;
	//map <int,int> m2;
	int m1 [300][300];
	int m2 [300][300];
	memset(m1,-1,sizeof(m1));
	memset(m2,-1,sizeof(m2));
	q1.push(startp);
	q2.push(endp);
	while(!q1.empty() || !q2.empty()){
		if (!q1.empty()){
			Pos q1now = q1.front();
			q1.pop();
			m1[q1now.x][q1now.y] = q1now.step;
			if (m2[q1now.x][q1now.y] != -1) return m2[q1now.x][q1now.y] + q1now.step;
			for (int i=0;i<8;i++){
				int nx = q1now.x + dx[i];
				int ny = q1now.y + dy[i];
				if (nx < 0 || ny < 0 || nx >= l || ny >= l) continue;
				if (m1[nx][ny] == -1) {
					q1.push(Pos(nx,ny,q1now.step+1));
					m1[nx][ny] = q1now.step + 1;
				}
			}
		}
		if (!q2.empty()){
			Pos q2now = q2.front();
			q2.pop();
			m2[q2now.x][q2now.y] = q2now.step;
			if (m1[q2now.x][q2now.y] != -1) return m1[q2now.x][q2now.y] + q2now.step;
			for (int i=0;i<8;i++){
				int nx = q2now.x + dx[i];
				int ny = q2now.y + dy[i];
				if (nx < 0 || ny < 0 || nx >= l || ny >= l) continue;
				if (m2[nx][ny] == -1) {
					q2.push(Pos(nx,ny,q2now.step+1));
					m2[nx][ny] = q2now.step + 1;
				}
			}
		}
	}
	return -1;
}
int main(){
	int T;
	cin >> T;
	while(T--){
		cin >> l >> startp.x >> startp.y >> endp.x >> endp.y;
		cout << solve() << endl;
	}
	return 0;
}
