#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

int main(){
	int n;
	while(scanf("%d",&n) == 1){
		int pos[1002] = {0};
		vector <int> g[1002];
		stack <int> s;
		for (int i=1;i<=n;i++){
			int t;
			scanf("%d",&t);
			pos[t] = i;
		}//BFS
		int root;
		scanf("%d",&root);
		s.push(root);
		for (int i=1;i<n;i++){
			int t;
			scanf("%d",&t);
			for(;;){
				int top = s.top();
				if (top == root || pos[top] + 1 < pos[t]){
					//栈顶为root时，一定只有子节点，当栈顶的点BFS顺序+1小于DFS所指点的BFS顺序时，该节点一定为子节点
					g[top].push_back(t);
					s.push(t);
					break;
				}
				else{
					s.pop();//不是子节点
				}
			}
		}
		for (int i=1;i<=n;i++){
			printf("%d:",i);
			for (vector<int>::iterator iter = g[i].begin();iter!=g[i].end();iter++)
				printf(" %d",*iter);
			printf("\n");
		}
	}

	return 0;
}