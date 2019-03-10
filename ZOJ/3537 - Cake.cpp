#include <bits/stdc++.h>
using namespace std;
int n,mo;
struct pos {
	int x,y;
	friend bool operator < (const pos &a,const pos &b) {
		return a.y < b.y || (a.y == b.y && a.x < b.x);
	}
}p[305];
struct mystack {
	pos a[305];
	int t;
	inline void init() {t = -1;}
	inline void push(pos i) {a[++t] = i;}
	inline void pop() {t--;}
	inline pos top() {return a[t];}
	inline pos sec() {return a[t-1];}
	inline bool available() {return t > 0;}
	inline int size() {return t+1;}
	inline int topindex() {return t;}
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
int f[305][305];
int cost(int i,int j) {
	if (j - i <= 1) return 0;
	int x = abs(s.a[i].x + s.a[j].x);
	int y = abs(s.a[i].y + s.a[j].y);
	return (x * y) % mo;
}
int main() {
	while (scanf("%d%d",&n,&mo) == 2) {
		for (int i=0;i<n;i++) scanf("%d%d",&p[i].x,&p[i].y);
		graham();
		if (s.size() == n + 1) {
			s.pop();
			memset(f,0x3f,sizeof(f));
			for (int i=0;i<n;i++) f[i][i+1] = 0;
			for (int len=3;len<=n;len++) {
				for (int i=0;i+len-1<n;i++) {
					int j = i + len - 1;
					for (int mid=i+1;mid<=j-1;mid++) {
						f[i][j] = min(f[i][j],f[i][mid] + f[mid][j] + cost(i,mid) + cost(mid,j));
					}
				}
			}
			printf("%d\n",f[0][n-1]);
		}
		else puts("I can't cut.");
	}
	
	return 0;
}
