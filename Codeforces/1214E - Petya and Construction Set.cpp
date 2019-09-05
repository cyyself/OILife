#include <bits/stdc++.h>
using namespace std;
struct DATA {
	int u,v,dis;
	friend bool operator < (const DATA &a,const DATA &b) {
		return a.dis > b.dis;
	}
}a[200005];
int num[200005];//长链上的节点编号
vector <pair<int,int> > ch[200005];//长链上的每个节点的非链之间的子节点
int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		a[i].u = i*2 + 1;
		a[i].v = i*2 + 2;
		scanf("%d",&a[i].dis);
	}
	sort(a,a+n);
	int len = a[0].dis + 1;
	num[1] = a[0].u;
	num[len] = a[0].v;
	int pos = 2;//现在长链上可以插入的位置
	for (int i=1;i<n;i++) {
		while (num[pos] && pos <= len) pos ++;
		if (pos == len + 1) {
			if (a[i].dis == 1) {
				ch[1].push_back({a[i].u,a[i].v});
			}
			else {
				int dis = a[i].dis - 2;
				ch[1].push_back({a[i].u,0});
				ch[1+dis].push_back({a[i].v,0});
			}
		}
		else {
			if (a[i].dis == 1) {
				num[pos] = a[i].u;
				ch[pos].push_back({a[i].v,0});
			}
			else {
				num[pos] = a[i].u;
				int dis = a[i].dis;
				if (pos + dis <= len && !num[pos+dis]) {
					num[pos+dis] = a[i].v;
				}
				else if (pos+dis == len+1) {
					len ++;
					num[pos+dis] = a[i].v;
				}
				else {
					dis -= 1;
					if (pos+dis <= len) {
						ch[pos+dis].push_back({a[i].v,0});
					}
					else if (pos-dis >= 1) {
						ch[pos-dis].push_back({a[i].v,0});
					}
					else assert(false);
				}
			}
		}
	}
	for (int i=1;i<=len;i++) {
		assert(num[i] != 0);
		if (i != len) printf("%d %d\n",num[i],num[i+1]);
		for (auto v:ch[i]) {
			printf("%d %d\n",num[i],v.first);
			if (v.second) printf("%d %d\n",v.first,v.second);
		}
	}
	return 0;
}
