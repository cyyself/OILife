#include <bits/stdc++.h>
using namespace std;
map <int,int> cnt;
vector <int> num[4];
map <int,vector<int> > pos;
int seq[100005];
int main() {
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int x;
		scanf("%d",&x);
		cnt[x] ++;
	}
	int p = 0;
	for (auto &x:cnt) num[x.second].push_back(x.first);
	for (auto x:num[3]) pos[x].push_back(p++);
	for (auto x:num[2]) pos[x].push_back(p++);
	for (int i=0;i<num[1].size()/2;i++) pos[num[1][i]].push_back(p++);
	for (auto x:num[3]) pos[x].push_back(p++);
	for (int i=num[1].size()/2;i<num[1].size();i++) pos[num[1][i]].push_back(p++);
	for (auto x:num[2]) pos[x].push_back(p++);
	for (auto x:num[3]) pos[x].push_back(p++);
	int ans = n;
	for (auto &x:pos) {
		vector <int> &s = x.second;
		for (int i=0;i<s.size()-1;i++) {
			ans = min(ans,s[i+1]-s[i]-1);
		}
	}
	printf("%d\n",ans);
	return 0;
}
