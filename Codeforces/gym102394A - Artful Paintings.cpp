#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 3005;
int head[maxn];
struct Edge {
	int v,w;
	int next;
}e[maxn*4];
int ecnt;
void addedge(int u,int v,int w) {
	e[ecnt].v = v;
	e[ecnt].w = w;
	e[ecnt].next = head[u];
	head[u] = ecnt;
	ecnt ++;
}
int xs[maxn*4];
int n;
 
bool inq[maxn];
int dis[maxn];
int cnt[maxn];
struct myqueue {
	int arr[maxn*maxn];
	int st,ed;
	inline void init() {
		st = 0;
		ed = 0;
	}
	inline bool empty() {
		return st == ed;
	}
	inline int front() {
		return arr[st];
	}
	inline void pop() {
		st ++;
	}
	inline void push(int x) {
		arr[ed] = x;
		ed ++;
	}
}q;
bool check(int mid) {
	for (register int i=0;i<=n;i++) {
		dis[i] = INF;
		cnt[i] = 0;
		inq[i] = false;
	}
	dis[0] = 0;
	//queue <int> q;
	q.init();
	q.push(0);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		cnt[u] ++;
		for (register int i=head[u];~i;i=e[i].next) {
			int v = e[i].v;
			int w = xs[i] * mid + e[i].w;
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				if (dis[v] < 0) return false;
				if (!inq[v]) {
					if (cnt[v] >= n) {
						return false;
					}
					q.push(v);
					inq[v] = true;
				}
			}
		}
	}
	return true;
}
namespace IO{
	#define BUF_SIZE 100000
	#define OUT_SIZE 100000
	bool IOerror=0;
	inline char nc(){
		static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
		if(p1==pend) {
			p1=buf;pend=buf+fread(buf,1,BUF_SIZE,stdin);
			if(pend==p1) {IOerror=1;return -1;}
		}
		return *p1++;
	}
	inline bool blank(char ch) {return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
	template<typename T> 
	inline bool read(T &x) {
		bool sign=0;char ch=nc();x=0;
		for(;blank(ch);ch=nc());
		if(IOerror) return false;
		if(ch=='-') sign=1,ch=nc();
		for(;ch>='0' && ch<='9';ch=nc()) x=x*10+ch-'0';
		if(sign) x=-x;
		return true;
	}
}
using namespace IO;
int main() {
	int T;
	//read(T);
	scanf("%d",&T);
	while (T --) {
		int m1,m2;
		//read(n);
		//read(m1);
		//read(m2);
		scanf("%d%d%d",&n,&m1,&m2);
		for (int i=0;i<2*n+m1+m2+2;i++) xs[i] = 0;
		for (int i=0;i<=n+1;i++) head[i] = -1;
		ecnt = 0;
		int _l = 0, _r = n;
		while (m1 --) {
			int l,r,k;
			//read(l);
			//read(r);
			//read(k);
			scanf("%d%d%d",&l,&r,&k);
			addedge(r,l-1,-k);
			_l = max(_l,k);
		}
		while (m2 --) {
			int l,r,k;
			//read(l);
			//read(r);
			//read(k);
			scanf("%d%d%d",&l,&r,&k);
			xs[ecnt] = 1;
			addedge(l-1,r,-k);
			_l = max(_l,k);
		}
		
		xs[ecnt] = -1;
		addedge(n,0,0);
		xs[ecnt] = 1;
		addedge(0,n,0);
 
		for (int i=n;i>=1;i--) {
			addedge(i,i-1,0);
			addedge(i-1,i,1);
		}
		int ans = -1;
		while (_l <= _r) {
			int mid = (_l + _r) / 2;
			if (check(mid)) {
				ans = mid;
				_r = mid - 1;
			}
			else {
				_l = mid + 1;
			}
		}
		assert(ans != -1);
		printf("%d\n",ans);
	}
}
