#include <cstdio>
using namespace std;
int N,M;
int x[10005][105];
int have_stair[10005][105];
int fr[10005];//有楼梯的房间数
int goup(int x,int now,int floor) {//nowroom
	int nx = x % fr[floor];
	if ()
	int cnt = 0;
	for (int i=now;i<=M;i++) {
		if (i == M) i = 0;
		if (have_stair[floor][i]) cnt ++;
		if ( (nx != 0 && cnt == nx) || cnt == x ) return i;
	}
	return -1;
}
int main() {
	int key = 0;
	scanf("%d%d",&N,&M);
	for (int i=0;i<N;i++) {
		for (int j=0;j<M;j++) {
			scanf("%d%d",&have_stair[i][j],&x[i][j]);
			if (have_stair[i][j]) fr[i]++;
		}
	}
	int last;
	scanf("%d",&last);
	for (int i=0;i<N;i++) {
		//printf("Debug  fr= %d\n",fr[i]);
		key = (key + x[i][last]) % 20123;
		last = goup(x[i][last],last,i);
	}
	printf("%d\n",key);
	return 0;
}