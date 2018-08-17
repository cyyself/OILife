#include <bits/stdc++.h>
using namespace std;
bool stop = false;
bool judge(int _x1,int _y1,int _x2,int _y2) {
	printf("? %d %d %d %d\n",_x1,_y1,_x2,_y2);
	fflush(stdout);
	char s[5];
	scanf("%s",s);
	if (s[0] == 'B') stop = true;
	return s[0] == 'Y';
}
char path[1005];
int main() {
	int n;
	scanf("%d",&n);
	int j = 0;
	int x = 1;
	int y = 1;
	for (int i=0;i<n-1 && !stop;i++) {//走一半
		if (y < n && judge(x,y+1,n,n)) {
			y ++;
			path[j++] = 'R';
		}
		else {
			x ++;
			path[j++] = 'D';
		}
	}
	x = n;
	y = n;
	j = 2 * n - 3;
	for (int i=0;i<n-1 && !stop;i++) {
		if (x > 1 && judge(1,1,x-1,y)) {
			x --;
			path[j--] = 'D';
		}
		else {
			y --;
			path[j--] = 'R';
		}
	}
	if (!stop) printf("! %s\n",path);
	return 0;
}
