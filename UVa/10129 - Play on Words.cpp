//欧拉道路
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int in[26];
int out[26];
bool vis[26];//false为visited或不需要vis
bool map[26][26];
void Search(int p){
	vis[p] = false;
	for (int i=0;i<26;i++) if (vis[i] && map[p][i]) Search(i);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		bool error = false;
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		memset(map,0,sizeof(map));
		memset(vis,0,sizeof(vis));
		int n;
		scanf("%d",&n);
		int start = 0;
		for (int i=0;i<n;i++){
			char a[1001];
			scanf("%s",&a[0]);
			int u = a[0]-'a';
			int v = a[strlen(a)-1]-'a';
			in[u]++;
			out[v]++;
			map[u][v] = true;
			vis[u] = true;
			vis[v] = true;
			start = u;
		}
		int ent = 0;//入口
		int exit = 0;//出口
		for (int i=0;i<26;i++){
			int diff = in[i]-out[i];
			if (diff == 1) {
				start = i;
				ent ++;
			}
			else if (diff == -1) exit ++;
			else if (diff != 0) {
				error = true;
				goto jud;
			}
		}
		if ((ent == 0 && exit == 0) || (ent == 1 && exit == 1)){
			Search(start);
			for (int i=0;i<26;i++) if (vis[i]){
				error = true;
				goto jud;
			}
		}
		else error = true;
		jud:
		if (error) printf("The door cannot be opened.\n");
		else printf("Ordering is possible.\n");
	}
	return 0;
}
