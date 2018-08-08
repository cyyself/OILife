#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int n,k;
int t[5];
struct edge {
	int v,w;
};
vector <edge> g[507];
int dis[507];
bool inq[507];
void spfa(int s) {
	memset(inq,false,sizeof(inq));
	memset(dis,0x3f,sizeof(dis));
	queue <int> q;
	q.push(s);
	inq[s] = true;
	dis[s] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		for (int i=0;i<g[u].size();i++) {
			edge e = g[u][i];
			if (dis[u] + e.w < dis[e.v]) {
				dis[e.v] = dis[u] + e.w;
				if (!inq[e.v]) {
					q.push(e.v);
					inq[e.v] = true;
				}
			}
		}
	}
}
string tmp;
bool stop[101][5];
inline int getnum(int floor,int elevator) {
	return (floor+1) + elevator * 101;
}
/*
编号规则：
	起点：0
	i层楼的j号电梯（电梯从0开始编号）：(i+1)+ j*101
	终点：5*101+1=>506
*/
int main() {
	while (scanf("%d%d",&n,&k) == 2) {
		//尽管只需要到k层，但是上面转下来可能更快，最开始我理解错了，然后忽略掉了上层
		for (int i=0;i<=506;i++) g[i].clear();
		memset(stop,false,sizeof(stop));
		for (int i=0;i<n;i++) scanf("%d",&t[i]);
		getline(cin,tmp);//skip "\n"
		for (int i=0;i<n;i++) {
			getline(cin,tmp);
			bool read = false;
			int cur = 0;
			int last = -1;
			for (int j=0;j<=tmp.length();j++) {
				if (j < tmp.length() && tmp[j] >= '0' && tmp[j] <= '9') {
					read = true;
					cur *= 10;
					cur += tmp[j] - '0';
				}
				else {
					if (read && last != -1) {
						g[getnum(cur,i)].push_back((edge){getnum(last,i),t[i]*(cur-last)});
						g[getnum(last,i)].push_back((edge){getnum(cur,i),t[i]*(cur-last)});
					}
					if (read) stop[cur][i] = true;
					if (read) last = cur;
					read = false;
					cur = 0;
				}
			}
		}
		for (int i=0;i<n;i++) {
			if (stop[0][i]) g[0].push_back((edge){getnum(0,i),0});
			if (stop[k][i]) g[getnum(k,i)].push_back((edge){506,0});
		}
		for (int i=0;i<=100;i++) 
			for (int j=0;j<n;j++) 
				if (stop[i][j]) 
					for (int _k=0;_k<n;_k++) 
						if (stop[i][_k] && j != _k) g[getnum(i,j)].push_back((edge){getnum(i,_k),60});
		//之前这里写k然后没注意到和前面冲突了，WA了半个小时
		spfa(0);
		if (dis[506] == INF) printf("IMPOSSIBLE\n");
		else printf("%d\n",dis[506]);
	}
	return 0;
}
