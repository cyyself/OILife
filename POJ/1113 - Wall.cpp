#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
const double pi = acos(-1.0);
struct pos {
	int x,y;
	friend bool operator < (const pos &a,const pos &b) {
		return a.y < b.y || (a.y == b.y && a.x < b.x);
	}
}p[1005];
struct stack {
	pos a[1005];
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
void gerham() {
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
inline double calcround(double r) {
	return pi * r * 2;
}
int main() {
	int l;
	while(scanf("%d%d",&n,&l) == 2) {
		for (int i=0;i<n;i++) scanf("%d%d",&p[i].x,&p[i].y);
		if (n == 2) {
			printf("0\n");
			continue;
		}
		gerham();
		double ans = calcround(l);
		for (int i=0;i<s.topindex();i++) ans += dis(s.a[i],s.a[i+1]);
		printf("%d\n",(int)(ans+0.5));
		//printf("%0.0lf\n",ans);在这里WA了一小时qwq
	}
	return 0;
}