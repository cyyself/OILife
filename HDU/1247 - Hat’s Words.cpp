//字母顺序不是字典序，被坑了好久
#include <bits/stdc++.h>
using namespace std;
map <string,bool> exist;
int n;
struct node {
	bool exist;
	node* ch[26];
	node() {
		memset(ch,0,sizeof(ch));
		exist = false;
	}
}root;
void insert(string s) {
	node *cur = &root;
	for (int i=0;i<s.length();i++) {
		int v = s[i] - 'a';
		if (cur->ch[v] == NULL) cur->ch[v] = new node;
		cur = cur->ch[v];
	}
	cur->exist = true;
}
bool judge(string s) {
	node *cur = &root;
	for (int i=0;i<s.length()-1;i++) {
		if (cur->ch[s[i] - 'a'] == NULL) break;
		cur = cur->ch[s[i] - 'a'];
		if (cur->exist) {
			if (exist[s.substr(i+1,s.length()-i-1)]) return true;
		}
	}
	return false;
}
vector <string> input;
int main() {
	string tmp;
	while (cin >> tmp) {
		input.push_back(tmp);
		exist[tmp] = true;
	}
	for (map<string,bool>::iterator it=exist.begin();it != exist.end();it++) insert(it->first);
	for (vector<string>::iterator it=input.begin();it != input.end();it++) if (judge(*it)) cout << *it << endl;
	return 0;
}
