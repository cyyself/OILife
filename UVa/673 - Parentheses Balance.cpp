#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;
int main(){
	int n;
	cin >> n;
	cin.get(); 
	while(n--){
		stack <char> d;
		bool ans = true;
		string s;
		getline(cin,s);
		for (int i=0;i<s.length();i++){
			if (!ans) break;
			switch(s[i]){
				case '(':
					d.push('(');
					break;
				case ')':
					if (!d.empty()){
						if (d.top()!='(') ans = false;
						d.pop();
					}
					else ans = false;
					break;
				case '[':
					d.push('[');
					break;
				case ']':
					if (!d.empty()){
						if (d.top()!='[') ans = false;
						d.pop();
					}
					else ans = false;
					break;
			}
		}
		if (ans && d.empty()) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
