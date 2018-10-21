#include <bits/stdc++.h>
using namespace std;
map <string,map<pair<int,int>,bool> > mem;//统计每个单词存在的文章的编号和文章行号
map <string,map<int,bool> > exist;//统计每个单词在每篇文章中是否存在
string txt[100][1501];
inline bool judge(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
inline set<int> uni(const set<int> &a,const set<int> &b) {
	set<int> ret;
	set_union(a.begin(),a.end(),b.begin(),b.end(),inserter(ret,ret.begin()));
	return ret;
}
inline set<int> ins(const set<int> &a,const set<int> &b) {
	set<int> ret;
	set_intersection(a.begin(),a.end(),b.begin(),b.end(),inserter(ret,ret.begin()));
	return ret;
}
string t;
int main() {
	int n;
	scanf("%d",&n);
	getline(cin,t);
	for (int i=0;i<n;i++) {
		int j = 0;
		while (getline(cin,txt[i][j]) && txt[i][j] != "**********") {
			string key = "";
			for (int k=0;k<txt[i][j].length();k++) {
				if (judge(txt[i][j][k])) {
					key += txt[i][j][k] | 32;
				}
				else {
					if (key != "") {
						mem[key][make_pair(i,j)] = true;
						exist[key][i] = true;
					}
					key = "";
				}
			}
			if (key != "") {
				mem[key][make_pair(i,j)] = true;
				exist[key][i] = true;
			}
			j ++;
		}
	}
	int q;
	scanf("%d",&q);
	getline(cin,t);
	while (q --) {
		getline(cin,t);
		if (t.substr(0,4) == "NOT ") {
			string key = t.substr(4);
			int lasttxt = -1;
			for (int i=0;i<n;i++) {
				if (exist[key][i]) continue;
				if (lasttxt != -1) cout << "----------\n";
				for (int j=0;txt[i][j] != "**********";j++) cout << txt[i][j] << "\n";
				lasttxt = i;
			}
			if (lasttxt == -1) cout << "Sorry, I found nothing.\n";
		}
		else {
			auto pos = t.find(" ");
			if (pos == string::npos) {
				//只有一个关键字
				int lasttxt = -1;
				for (auto x:mem[t]) {
					if (!x.second) continue;
					if (lasttxt != -1 && x.first.first != lasttxt) cout << "----------\n";
					lasttxt = x.first.first;
					cout << txt[x.first.first][x.first.second] << "\n";
				}
				if (lasttxt == -1) cout << "Sorry, I found nothing.\n";

			}
			else {
				if (t.substr(pos+1,2) == "OR") {
					string key1 = t.substr(0,pos);
					string key2 = t.substr(pos+4);
					set <pair<int,int> > ans;
					for (auto x:mem[key1]) if (x.second) ans.insert(x.first);
					for (auto x:mem[key2]) if (x.second) ans.insert(x.first);
					int lasttxt = -1;
					for (auto x:ans) {
						if (lasttxt != -1 && lasttxt != x.first) cout << "----------\n";
						cout << txt[x.first][x.second] << endl;
						lasttxt = x.first;
					}
					if (lasttxt == -1) cout << "Sorry, I found nothing.\n";
				}
				else {
					//AND
					string key1 = t.substr(0,pos);
					string key2 = t.substr(pos+5);
					int lasttxt = -1;
					for (int i=0;i<n;i++) {
						if (!exist[key1][i] || !exist[key2][i]) continue;
						if (lasttxt != -1) cout << "----------\n";
						for (int j=0;txt[i][j] != "**********";j++) if (mem[key1][make_pair(i,j)] || mem[key2][make_pair(i,j)]) cout << txt[i][j] << "\n";
						lasttxt = i;
					}
					if (lasttxt == -1) cout << "Sorry, I found nothing.\n";
				}
			}
		}
		cout << "==========\n";
	}
	return 0;
}
