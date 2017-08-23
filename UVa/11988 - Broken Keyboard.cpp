//UVa 11988
#include <iostream>
#include <cstring>
using namespace std;
string s;
struct d{
	string s;
	d* next;
	d():next(NULL),s(""){}
};
void deld(d* u){
	if (u == NULL) return;
	deld(u->next);
	delete u;
}
d* root;
d* back;
void push_back(string s){
	if (back->s != ""){
		back->next = new d;
		back = back->next;
	}
	back->s = s;
}
void push_front(string s){
	d* p = new d;
	p->s = s;
	p->next = root;
	root = p;
}
int main(){
	std::ios::sync_with_stdio(false);
	while(cin >> s){
		int status = 0;
		string t="";
		root = new d;
		back = root;
		for (int i=0;i<s.length();i++){
			if (s[i] == '['){
				if (status) push_front(t);
				else push_back(t);
				t = "";
				status = 1;
			}
			else if (s[i] == ']'){
				if (status) push_front(t);
				else push_back(t);
				t = "";
				status = 0;
			}
			else{
				t+=s[i];
			}
		}
		if (status) push_front(t);
		else push_back(t);
		//output
		d* p;
		for (p=root;p->next!=NULL;p=p->next) cout << p->s;
		cout << p->s;
		cout << endl;
		deld(root);
	}
	return 0;
}
