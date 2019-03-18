//https://pintia.cn/problem-sets/994805046380707840/problems/994805049455132672
#include <bits/stdc++.h>
using namespace std;
unordered_map <string,int> ls;
unordered_map <int,string> rls;
int lscnt;
int getls(string name) {
	if (ls.find(name) == ls.end()) ls[name] = ++lscnt;
	rls[ls[name]] = name;
	return ls[name];
}
int d[205][205];//距离
int p[205][205];//经过的城镇
int w[205][205];//歼敌数
int _w[205];//每个点的敌人数
int c[205][205];//方案数
int pre[205][205];//pre[i][j]=k表示，[i][j]从[i][k]到[k][j]
void print_route(int l,int r) {
	if (pre[l][r] == 0) cout << "->" << rls[r];
	else {
		print_route(l,pre[l][r]);
		print_route(pre[l][r],r);
	}
}
int main() {
	memset(d,0x3f,sizeof(d));
	int n,m;
	cin >> n >> m;
	string tmp;
	cin >> tmp;
	int s = getls(tmp);
	cin >> tmp;
	int t = getls(tmp);
	for (int i=1;i<n;i++) {
		int x;
		cin >> tmp >> x;
		_w[getls(tmp)] = x;
	}
	for (int i=0;i<m;i++) {
		cin >> tmp;
		int u = getls(tmp);
		cin >> tmp;
		int v = getls(tmp);
		int w;
		cin >> w;
		d[u][v]= d[v][u] = min(d[u][v],w);
	}
	for (int i=1;i<=lscnt;i++) for (int j=1;j<=lscnt;j++) {
		w[i][j] = _w[i] + _w[j];
		p[i][j] = 2;
		c[i][j] = 1;
	}
	for (int k=1;k<=lscnt;k++) {
		for (int i=1;i<=lscnt;i++) 
			for (int j=1;j<=lscnt;j++) {
				if (d[i][k] + d[k][j] < d[i][j]) {
					d[i][j] = d[i][k] + d[k][j];
					p[i][j] = p[i][k] + p[k][j] - 1;
					w[i][j] = w[i][k] + w[k][j] - _w[k];
					pre[i][j] = k;
					c[i][j] = c[i][k] * c[k][j];
				}
				else if (d[i][k] + d[k][j] == d[i][j]) {
					c[i][j] += c[i][k] * c[k][j];
					if (p[i][k] + p[k][j] - 1 > p[i][j]) {
						p[i][j] = p[i][k] + p[k][j] - 1;
						w[i][j] = w[i][k] + w[k][j] - _w[k];
						pre[i][j] = k;
					}
					else if (p[i][k] + p[k][j] - 1 == p[i][j]) {
						if (w[i][k] + w[k][j] - _w[k] > w[i][j]) {
							w[i][j] = w[i][k] + w[k][j] - _w[k];
							pre[i][j] = k;
						}
					}
				}
			}
	}
	cout << rls[s];
	print_route(s,t);
	cout << endl;
	printf("%d %d %d\n",c[s][t],d[s][t],w[s][t]);
	return 0;
}
