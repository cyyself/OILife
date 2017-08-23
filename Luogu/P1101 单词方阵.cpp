#include <iostream>
using namespace std;
string g[105];
bool mark[105][105];
int n;
const string word = "yizhong";
void check(int x,int y,int dx,int dy){
	int nx = x;
	int ny = y;
	for (int i=0;i<word.length();i++) {
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) return;
		if (g[nx][ny] != word[i]) return;
		nx += dx;
		ny += dy;
	}
	nx -= dx;
	ny -= dy;
	for (int i=0;i<word.length();i++) {
		mark[nx][ny] = true;
		nx -= dx;
		ny -= dy;
	}
}
int main() {
	cin >> n;
	for (int i=0;i<n;i++) cin >> g[i];
	for (int i=0;i<n;i++) for (int j=0;j<n;j++) {
		if (g[i][j] == 'y' && !mark[i][j]) {
			const int dx[] = {1,1,1,0,0,-1,-1,-1};
			const int dy[] = {1,0,-1,1,-1,1,0,-1};
			for (int k=0;k<8;k++) check(i,j,dx[k],dy[k]);
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++) {
			if (mark[i][j]) cout << g[i][j];
			else cout << "*";
		}
		cout << endl;
	}
	return 0;
}