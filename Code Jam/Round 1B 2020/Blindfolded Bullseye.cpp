#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int ask(int x,int y) {
	x = max((int)-1e9,min(x,(int)1e9));
	y = max((int)-1e9,min(y,(int)1e9));
	printf("%d %d\n",x,y);
	fflush(stdout);
	char s[10];
	scanf("%s",s);
	if (s[0] == 'M') return -1;
	else if (s[0] == 'C') return 1;
	else return 0;
}
int rand(int l,int r) {
	return l + rand() % (r - l + 1);
}
int bs_rx(int y,int l,int r) {//binary search right most miss x
	int res = -inf;
	while (l <= r) {
		int mid = (l + r) >> 1;
		int tmp = ask(mid,y);
		if (tmp == 1) return inf;
		else {
			if (tmp == -1) {
				res = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
	}
	assert(res != -inf);
	return res;
}
int bs_lx(int y,int l,int r) {//binary search left most miss x
	int res = -inf;
	while (l <= r) {
		int mid = (l + r) >> 1;
		int tmp = ask(mid,y);
		if (tmp == 1) return inf;
		else {
			if (tmp == -1) {
				res = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
	}
	assert(res != -inf);
	return res;
}
int bs_dy(int x,int l,int r) {//binary search down most miss y
	int res = -inf;
	while (l <= r) {
		int mid = (l + r) >> 1;
		int tmp = ask(x,mid);
		if (tmp == 1) return inf;
		else {
			if (tmp == -1) {
				res = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
	}
	assert(res != -inf);
	return res;
}
int bs_uy(int x,int l,int r) {//binary search up most miss y
	int res = -inf;
	while (l <= r) {
		int mid = (l + r) >> 1;
		int tmp = ask(x,mid);
		if (tmp == 1) return inf;
		else {
			if (tmp == -1) {
				res = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
	}
	assert(res != -inf);
	return res;
}
int a,b;
void work() {
	/*
	vector <int> sx,sy;
	for (int i=0;i<45;i++) {
		int x = rand(-1e9,1e9);
		int y = rand(-1e9,1e9);
		int res = ask(rand(-1e9,1e9),rand(-1e9,1e9));
		if (res == 1) return;
		else if (res == 0) {
			sx.push_back(x);
			sy.push_back(y);
		}
	}
	sort(sx.begin(),sx.end());
	sort(sy.begin(),sy.end());
	int cx = sx[sx.size()/2], cy = sy[sy.size()/2];
	*/
	int cx,cy;
	while (true) {
		int x = rand(-1e9,1e9);
		int y = rand(-1e9,1e9);
		int res = ask(x,y);
		if (res == 1) return;
		else {
			if (res == 0) {
				cx = x;
				cy = y;
				break;
			}
		}
	}
	//cerr << cx << "," << cy << endl;
	//exit(-1);
	int xl = bs_rx(cy,-1e9,cx);
	if (xl == inf) return;
	int xr = bs_lx(cy,cx,1e9);
	if (xr == inf) return;
	int yu = bs_dy(cx,-1e9,cy);
	if (yu == inf) return;
	int yd = bs_uy(cx,cy,1e9);
	if (yd == inf) return;
	int x = (xl + xr) / 2;
	int y = (yu + yd) / 2;
	for (int dx=-5;dx<=5;dx++)
		for (int dy=-5;dy<=5;dy++) {
			int res = ask(x+dx,y+dy);
			assert(res != -1);
			if (res == 1) return;
		}
	assert(false);
}
int main() {
	srand(time(NULL));
	int T;
	scanf("%d%d%d",&T,&a,&b);
	while (T --) work();
	return 0;
}
