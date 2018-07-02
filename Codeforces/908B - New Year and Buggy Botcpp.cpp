#include <bits/stdc++.h>
using namespace std;
char maze[55][55];
int n,m;
char s[105];
int slen;
int sx = -1;
int sy = -1;
int cmd[4] = {0,1,2,3};
int ans;
char trans(int dir) {
	switch (dir) {
		case 0:
			return 'D';
		case 1:
			return 'R';
		case 2:
			return 'U';
		case 3:
			return 'L';
	}
	return '0';
}
bool judge() {
	int curx = sx;
	int cury = sy;
	for (int i=0;i<slen;i++) {
		int ccmd = cmd[s[i]-'0'];
		switch (ccmd) {
			case 0:
				curx ++;
				break;
			case 1:
				cury ++;
				break;
			case 2:
				curx --;
				break;
			case 3:
				cury --;
				break;
		}
		if (maze[curx][cury] == 'E') return true;
		if (maze[curx][cury] == '#') return false;
		if (curx >= n || cury >= m || curx < 0 || cury < 0) return false;
	}
	return false;
	//printf("Debug: Reached %c\n",maze[curx][cury]);
	//if (maze[curx][cury] == 'E') return true;
	//else return false;
}
int main() {
	//freopen("1.in","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf("%s",maze[i]);
	for (int i=0;i<n && sx == -1;i++) 
		for (int j=0;j<m && sy == -1;j++) 
			if (maze[i][j] == 'S') {
				sx = i;
				sy = j;
			}
	scanf("%s",s);
	slen = strlen(s);
	do {
		//printf("Debug: Testing (%c,%c,%c,%c)\n",trans(cmd[0]),trans(cmd[1]),trans(cmd[2]),trans(cmd[3]));
		if (judge()) ans ++;
	} while(next_permutation(cmd,cmd+4));
	printf("%d\n",ans);
	return 0;
}