#include <bits/stdc++.h>
using namespace std;
struct person {
	string name;
	int score;
	friend bool operator < (const person &a,const person &b) {
		return a.score > b.score;
	}
};
vector <person> team[10005];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	while (n--) {
		string name;
		int r,s;
		cin >> name >> r >> s;
		team[r].push_back((person){name,s});
	}
	for (int i=1;i<=m;i++) {
		sort(team[i].begin(),team[i].end());
		if (team[i].size() >= 3 && team[i][1].score == team[i][2].score) cout << "?\n";
		else cout << team[i][0].name << " " << team[i][1].name << endl;
	}
	return 0;
}
