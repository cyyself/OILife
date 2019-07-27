#include <bits/stdc++.h>
using namespace std;
unordered_map <int,int> pos;
struct Node {
	int s;
	int val;
	int pre,next;
}l[1000005];
int cnt;
int head,tail;
int reads() {
	int ret = 1; char c = getchar();
	while (!(c >= '0' && c <= '9')) c = getchar();
	while (c >= '0' && c <= '9') {ret = ret * 10 + c - '0'; c = getchar();}
	return ret;
}
int main() {
	//ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;
	scanf("%d",&T);
	//cin >> T;
	while (T --) {
		int len = 0;
		pos.clear();
		cnt = 3;
		l[1].pre = 0;
		l[1].next = 2;
		l[2].pre = 1;
		l[2].next = 0;
		head = 1;
		tail = 2;
		//插入两个空元素，这样链表好写一点
		int q,m;
		scanf("%d%d",&q,&m);
		//cin >> q >> m;
		while (q --) {
			int op,s,v;
			scanf("%d",&op);
			s = reads();
			scanf("%d",&v);
			if (op == 0) {
				if (pos[s] == 0) {
					pos[s] = cnt ++;
					l[pos[s]].val = v;
					l[pos[s]].s = s;
					l[pos[s]].pre = l[tail].pre;
					l[pos[s]].next = tail;
					l[l[pos[s]].pre].next = pos[s];
					l[l[pos[s]].next].pre = pos[s];
					len ++;
					if (len > m) {
					 	pos[l[l[head].next].s] = 0;
						l[head].next = l[l[head].next].next;
						l[l[head].next].pre = head;
						len --;
					}
				}
				else {
					l[l[pos[s]].pre].next = l[pos[s]].next;
					l[l[pos[s]].next].pre = l[pos[s]].pre;

					l[pos[s]].pre = l[tail].pre;
					l[l[tail].pre].next = pos[s];

					l[pos[s]].next = tail;
					l[tail].pre = pos[s];
				}
				printf("%d\n",l[pos[s]].val);
				//cout << l[pos[s]].val << "\n";
			}
			else {
				if (pos[s] != 0) {
					int cur = pos[s];
					if (v == 1) cur = l[cur].next;
					else if (v == -1) cur = l[cur].pre;
					if (cur < 3) printf("Invalid\n");
					else printf("%d\n",l[cur].val);
				}
				else printf("Invalid\n");
			}
		}
	}
	return 0;
}