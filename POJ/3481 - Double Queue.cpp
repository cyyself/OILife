#include <cstdio>
#include <queue>
using namespace std;
struct client {
	int id,k,p;
	friend bool operator < (const client &a,const client &b) {
		return a.p < b.p;
	}
};
priority_queue <client> q1;
priority_queue <client> q2;
bool vis[10000000];
void clean() {
	while (!q1.empty()) {
		client a = q1.top();
		if (vis[a.id]) q1.pop();
		else break;
	}
	while (!q2.empty()) {
		client a = q2.top();
		if (vis[a.id]) q2.pop();
		else break;
	}
}
int main() {
	int op;
	int idx = 0;
	while (scanf("%d",&op) == 1 && op) {
		if (op == 1) {
			int k,p;
			scanf("%d%d",&k,&p);
			q1.push((client){idx,k,p});
			q2.push((client){idx,k,-p});
			idx ++;
		}
		else if (op == 2) {
			if (q1.empty()) puts("0");
			else {
				client a = q1.top();
				q1.pop();
				vis[a.id] = true;
				printf("%d\n",a.k);
				clean();
			}
		}
		else {
			if (q2.empty()) puts("0");
			else {
				client a = q2.top();
				q2.pop();
				vis[a.id] = true;
				printf("%d\n",a.k);
				clean();
			}
		}
	}
	return 0;
}
