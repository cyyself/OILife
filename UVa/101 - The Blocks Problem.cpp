#include <bits/stdc++.h>
using namespace std;
vector <int> p[26];
int n;
pair<int,int> find(int x) {
	for (int i=0;i<n;i++) for (unsigned int j=0;j<p[i].size();j++) if (p[i][j] == x) return make_pair(i,j);
}
int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) p[i].push_back(i);
	string oa,ob;
	int a,b;
	while (cin >> oa) {
		if (oa == "quit") break;
		cin >> a >> ob >> b;
		pair<int,int> posa = find(a);
		pair<int,int> posb = find(b);
		if (posa.first == posb.first) continue;
		if (ob == "onto") {
			for (unsigned int j=posb.second+1;j<p[posb.first].size();j++) {
				int x = p[posb.first][j];
				p[x].push_back(x);
			}
			p[posb.first].resize(posb.second+1);
		}
		if (oa == "move") {
			for (unsigned int j=posa.second+1;j<p[posa.first].size();j++) {
				int x = p[posa.first][j];
				p[x].push_back(x);
			}
			p[posa.first].resize(posa.second+1);
		}
		for (unsigned int j=posa.second;j<p[posa.first].size();j++) {
			int x = p[posa.first][j];
			p[posb.first].push_back(x);
		}
		p[posa.first].resize(posa.second);
	}
	for (int i=0;i<n;i++) {
		printf("%d:",i);
		for (auto x:p[i]) printf(" %d",x);
		printf("\n");
	}
	return 0;
}
