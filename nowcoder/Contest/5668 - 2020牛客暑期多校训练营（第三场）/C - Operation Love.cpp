#include <bits/stdc++.h>
using namespace std;
int n;
struct pos {
	double x,y;
	friend bool operator < (const pos &a,const pos &b) {
		return a.y < b.y || (a.y == b.y && a.x < b.x);
	}
}p[25];
struct stack {//不用STL的原因是STL不能输出栈的次顶元素
	pos a[105];
	int t;
	inline void init() {
		t = -1;
	}
	inline void push(pos i) {
		a[++t] = i;
	}
	inline void pop() {
		t--;
	}
	inline pos top() {
		return a[t];
	}
	inline pos sec() {//次顶
		return a[t-1];
	}
	inline bool available() {
		return t > 0;//至少有两个元素
	}
	inline int size() {
		return t+1;
	}
	inline int topindex() {
		return t;
	}
}s;
inline bool judge(const pos &e,const pos &c,const pos &s) {
	return (e.x - s.x) * (c.y - s.y) - (c.x - s.x) * (e.y - s.y) >= 0;
}
void graham() {
	sort(p,p+n);
	s.init();
	for (int i=0;i<min(2,n);i++) s.push(p[i]);
	if (n > 2) {
		for (int i=2;i<n;i++) {
			while (s.available() && judge(p[i],s.top(),s.sec())) s.pop();
			s.push(p[i]);
		}
		int len = s.size();
		s.push(p[n-2]);
		for (int i=n-3;i>=0;i--) {
			while (s.size() > len && judge(p[i],s.top(),s.sec())) s.pop();
			s.push(p[i]);
		}
	}
	else s.push(p[0]);
}
inline double dis(const pos &a,const pos &b) {
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
const double eps = 1e-1;
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		n = 20;
		for (int i=0;i<n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
		graham();
		vector <double> ed;
		for (int i=0;i<s.size()-1;i++) ed.push_back(dis(s.a[i],s.a[i+1]));
		int idx = 0;
		for (int i=0;i<ed.size();i++) if (abs(ed[i] - 9) < eps) {
			idx = i;
			break;
		}
		if (abs(ed[(idx+1)%ed.size()] - 8) < eps) printf("right\n");
		else printf("left\n");
	}
	return 0;
}
