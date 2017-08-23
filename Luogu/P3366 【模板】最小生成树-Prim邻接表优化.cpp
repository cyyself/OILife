//基于Prim算法的邻接表优化
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
struct Edge{
	int to;
	int weight;
	Edge(int _to,int _weight):to(_to),weight(_weight){}
};
vector <Edge> g[5005];//邻接表
int main() {
	ios::sync_with_stdio(false);
	int N,M;
	cin >> N >> M;
	for (int i=0;i<M;i++) {
		int X,Y,Z;
		cin >> X >> Y >> Z;
		g[X].push_back(Edge(Y,Z));
		g[Y].push_back(Edge(X,Z));
		//无向图
	}
	int dis[5005];
	bool flag[5005]={0};//该点是否已加入最小生成树
	memset(dis,0x7f,sizeof(dis));
	int k = 1;//从1号点开始扩展
	int tot = 0;
	while(k != -1){
		flag[k] = true;//标记该点已加入生成树中
		for (int i=0;i<g[k].size();i++)//找出已扩展的所有点中到可抵达点距离最小值
			if (!flag[g[k][i].to] && g[k][i].weight < dis[g[k][i].to])
				dis[g[k][i].to] = g[k][i].weight;
		int l = 0x7f7f7f7f;//INF
		k = -1;//检测是否选择到了点
		for (int i=1;i<=N;i++) {//在未扩展的点中找到一条最短的边，如果找不到则算法结束
			if (!flag[i] && dis[i] < l) {
				l = dis[i];
				k = i;
			}
		}
		if (k != -1) tot += l;//在tot中加上这条边的长度
		//每次从新的k开始扩展
	}
	for (int i=1;i<=N;i++) {
		if (!flag[i]) {//判断每个点是否都加入了最小生成树
			cout << "orz" << endl;
			return 0;
		}
	}
	cout << tot << endl;
	return 0;
}