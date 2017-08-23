#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge {
	int from;
	int to;
	Edge():from(0),to(0){}
	Edge(int _from,int _to):from(_from),to(_to){}
}e[5005];
vector <Edge> reachable;
vector <Edge> ans;
int family[155];
int n,m;
int find(int x) {
	int result;
	if (family[x] == x) {
		result = x;
	}
	else {
		result = find(family[x]);
	}
	family[x] = result;
	return result;
}
void uni(int x,int y) {
	family[find(x)] = find(y);
}
bool comp(Edge a,Edge b) {
	if (a.from < b.from) return true;
	else if (a.from == b.from && a.to < b.to) return true;
	return false;
}
int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) family[i] = i;
	for (int i=0;i<m;i++) {
		scanf("%d%d",&e[i].from,&e[i].to);
		if (e[i].from > e[i].to) swap(e[i].from,e[i].to);
		uni(e[i].from,e[i].to);
	}
	for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++) if (find(i) == find(j)) reachable.push_back(Edge(i,j));
	//init ok
	for (int i=0;i<m;i++) {
		for (int j=1;j<=n;j++) family[j] = j;
		for (int j=0;j<m;j++) {
			if (j == i) continue;
			uni(e[j].from,e[j].to);
		}
		for (int j=0;j<reachable.size();j++) {
			if (find(reachable[j].from) != find(reachable[j].to)) {
				ans.push_back(e[i]);
				break;
			}
		}
	}
	sort(ans.begin(),ans.end(),comp);
	for (int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].from,ans[i].to);
	
	return 0;
}