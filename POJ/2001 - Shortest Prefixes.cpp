#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
struct Trie{
	int cnt;
	char c;
	Trie *child[26];
	Trie():cnt(0),c('\0') {
		memset(child,0,sizeof(child));
	}
}root;
string list[1005];
int cnt = 0;
void insert(const string &s) {
	Trie *n = &root;
	for (int i=0;i<s.length();i++) {
		if (n->child[s[i]-'a'] == NULL) n->child[s[i]-'a'] = new Trie;
		n=n->child[s[i]-'a'];
		n->c=s[i];
		n->cnt ++;
	}
}
string query(const string &s) {
	Trie *n = &root;
	string ans = "";
	for (int i=0;i<s.length();i++) {
		n = n->child[s[i]-'a'];
		ans += s[i];
		if (n->cnt == 1) return ans;
	}
	return ans;
}
int main() {
	while(cin >> list[cnt]) {
		if (list[cnt] == "") break;
		insert(list[cnt]);
		cnt ++;
	}
	for (int i=0;i<cnt;i++) {
		cout << list[i] << " " <<query(list[i]) << endl;
	}
	
	return 0;
}