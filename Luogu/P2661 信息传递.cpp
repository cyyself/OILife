#include <cstdio>
#include <cstring>
using namespace std;
int n;
int li[200005];//link
int seq[200005];//每个节点的访问顺序，-1代表已经看过
int seqi =0;//当前访问顺序编号
int ans = 200005;
void DFS(int node){
	if (seq[node] > 0) {
		if (seqi - seq[node] + 1 < ans) ans = seqi - seq[node] + 1;
	}
	else{
		if (seq[node] == 0){
			seq[node] = ++seqi;
			DFS(li[node]);
		}
	}
	seq[node] = -1;//vis
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&li[i]);
	for (int i=1;i<=n;i++) if (seq[i] == 0) DFS(i);
	printf("%d\n",ans);
	return 0;
}