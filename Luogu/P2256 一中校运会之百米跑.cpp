#include <iostream>
#include <map>
#include <vector>
using namespace std;
int family[20005];
int N,M;
vector <int>Link[20005];
void DFS(int Point,int value) {
	family[Point] = value;
	for (int i=0;i<Link[Point].size();i++) {
		int Link_to = Link[Point][i];
		if (family[Link_to] == 0) DFS(Link_to,value);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M;
	map<string,int> mem;
	int cnt = 0;
	for (int i=1;i<=N;i++) {
		string t;
		cin >> t;
		mem[t] = ++cnt;
	}
	for (int i=0;i<M;i++) {
		string a,b;
		cin >> a >> b;
		Link[mem[a]].push_back(mem[b]);
		Link[mem[b]].push_back(mem[a]);
	}
	for (int i=0;i<N;i++) if(family[i]==0)DFS(i,i);
	int K;
	cin >> K;
	for (int i=0;i<K;i++) {
		string a,b;
		cin >> a >> b;
		if (family[mem[a]] == family[mem[b]]) cout << "Yes." << endl;
		else cout << "No." << endl;
	}
	return 0;
}