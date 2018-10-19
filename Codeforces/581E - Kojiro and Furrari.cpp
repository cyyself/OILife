#include <bits/stdc++.h>
using namespace std;
vector <int> g[3];//g[i]存储类型小于等于i-1的加油站位置
int f[3][200005];//f[i][j]表示使用type>=i+1的油，在第j个加油站(加油站位置与g[i]有关，查找位置需对g[i]进行二分)，一直走到e装不下的油量
int e,s,n,m;
int cal(int type,int pos) {
	int index = lower_bound(g[type].begin(),g[type].end(),pos) - g[type].begin();
	return f[type][index] + max(g[type][index] - pos - s,0);
}
int main() {
	scanf("%d%d%d%d",&e,&s,&n,&m);
	for (int i=0;i<n;i++) {
		int t,x;
		scanf("%d%d",&t,&x);
		if (x > e) continue;
		for (int j=0;j<t;j++) g[j].push_back(x);
	}
	for (int i=0;i<3;i++) {
		g[i].push_back(e);
		sort(g[i].begin(),g[i].end());
		for (int j=g[i].size()-2;j>=0;j--) {
			f[i][j] = f[i][j+1] + max(g[i][j+1]-g[i][j]-s,0);//计算每次到下一个加油站装不下的油量
		}
	}
	for (int i=0;i<m;i++) {
		int pos;
		scanf("%d",&pos);
		if (cal(0,pos)) printf("-1 -1\n");//如果使用[1,3]号油都出现了装不下的情况，那么必然无解
		else {
			int tmp = cal(1,pos);//使用[2,3]号油需要补充的油量，即需要加的1号油的油量
			printf("%d %d\n",tmp,cal(2,pos)-tmp);//使用3号油的油量=(只使用[3]号油需要补充的油量，即使用[1,2]号油的油量)-（使用[2,3]号油需要补充的油量，即使用[1]号油的油量）
		}
	}
	return 0;
}
