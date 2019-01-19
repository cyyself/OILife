#include <bits/stdc++.h>
using namespace std;
vector <int> x;
vector <int> y;
map <pair<int,int>,bool> exist;
int main() {
	for (int i=0;i<8;i++) {
		int _x,_y;
		scanf("%d%d",&_x,&_y);
		x.push_back(_x);
		y.push_back(_y);
		exist[make_pair(_x,_y)] = true;
	}
	sort(x.begin(),x.end());
	auto it = unique(x.begin(),x.end());
	x.erase(it,x.end());
	sort(y.begin(),y.end());
	it = unique(y.begin(),y.end());
	y.erase(it,y.end());
	if (x.size() != 3 || y.size() != 3) puts("ugly");
	else {
		bool ans = true;
		if (!exist[make_pair(x[0],y[0])]) ans = false;
		if (!exist[make_pair(x[0],y[1])]) ans = false;
		if (!exist[make_pair(x[0],y[2])]) ans = false;
		if (!exist[make_pair(x[1],y[0])]) ans = false;
		if (!exist[make_pair(x[1],y[2])]) ans = false;
		if (!exist[make_pair(x[2],y[0])]) ans = false;
		if (!exist[make_pair(x[2],y[1])]) ans = false;
		if (!exist[make_pair(x[2],y[2])]) ans = false;
		if (ans) puts("respectable");
		else puts("ugly");
	}
	return 0;
}
