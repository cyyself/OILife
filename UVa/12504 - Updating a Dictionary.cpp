#include <bits/stdc++.h>
using namespace std;
string t;
void read(map<string,pair<bool,int> > &dst) {
	getline(cin,t);
	t = t.substr(1);
	t[t.length()-1] = ',';
	string curkey;
	int curval = 0;
	bool readval = false;
	for (int i=0;i<t.length();i++) {
		if (t[i] == ':') {
			readval = true;
			continue;
		}
		if (t[i] == ',') {
			if (curkey != "") dst[curkey] = make_pair(true,curval);//要考虑{}的情况
			curval = 0;
			curkey = "";
			readval = false;
			continue;
		}
		if (!readval) curkey += t[i];
		else {
			curval *= 10;
			curval += t[i] - '0';
		}
	}
}
void debug() {

}
int main() {
	int T;
	scanf("%d",&T);
	getline(cin,t);
	while (T --) {
		map<string,pair<bool,int> > a;
		read(a);
		map<string,pair<bool,int> > b;
		read(b);
		set <string> add,del,mod;
		for (auto p:b) if (p.second.first && !a[p.first].first) add.insert(p.first);
		for (auto p:a) if (p.second.first && !b[p.first].first) del.insert(p.first);
		for (auto p:b) if (p.second.first && a[p.first].first && a[p.first].second != p.second.second) mod.insert(p.first);
		if (add.size() + del.size() + mod.size() == 0) printf("No changes\n");
		else {
			if (add.size()) {
				printf("+");
				bool first = true;
				for(auto x:add) {
					if (!first) printf(",");
					cout << x;
					first = false;
				}
				printf("\n");
			}
			if (del.size()) {
				printf("-");
				bool first = true;
				for(auto x:del) {
					if (!first) printf(",");
					cout << x;
					first = false;
				}
				printf("\n");
			}
			if (mod.size()) {
				printf("*");
				bool first = true;
				for(auto x:mod) {
					if (!first) printf(",");
					cout << x;
					first = false;
				}
				printf("\n");
			}
		}
		printf("\n");
	}
	return 0;
}
