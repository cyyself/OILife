#include <bits/stdc++.h>
using namespace std;
string t;
struct book {
	string name;
	string author;
	friend bool operator < (const book &a,const book &b) {
		return a.author < b.author;
	}
};
vector <book> lib;
map <string,string> author;
int main() {
	while (getline(cin,t) && t != "END") {
		int pos = t.find("\"",1);
		author[t.substr(0,pos+1)] = t.substr(pos+5);
		lib.push_back((book){t.substr(0,pos+1),author[t.substr(0,pos+1)]});
	}
	sort(lib.begin(),lib.end());
	/*
	cout << endl;
	for (auto b:lib) cout << b.name << endl;
	cout << endl;
	*/
	vector <book> table;
	while (getline(cin,t) && t != "END") {
		if (t[0] == 'B') {
			string book_name = t.substr(7);
			lib.erase(lower_bound(lib.begin(),lib.end(),(book){book_name,author[book_name]}));
		}
		else if (t[0] == 'R') {
			string book_name = t.substr(7);
			table.push_back((book){book_name,author[book_name]});
		}
		else {//SHELVE
			sort(table.begin(),table.end());
			for (auto b:table) {
				auto pos = lower_bound(lib.begin(),lib.end(),b);
				if (pos == lib.begin()) cout << "Put " << b.name << " first\n";
				else cout << "Put "<< b.name <<" after " << (pos-1)->name << "\n";
				lib.insert(pos,b);
			}
			table.clear();
			cout << "END\n";
		}
	}
	return 0;
}
