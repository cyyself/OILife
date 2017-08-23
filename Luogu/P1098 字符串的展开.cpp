#include <iostream>
using namespace std;
bool IsCharacter(char a){
	if (a >= 97 && a <= 122) return true;
	return false;
}
string expand(char b,char e,int p1,int p2,int p3){
	string out;
	bool character = IsCharacter(b);
	for (int i = b + 1;i < e;i++){
		char c = i;
		switch(p1){
			case 2:
				if (character) c -= 32;
				break;
			case 3:
				c = '*';
				break;
		}
		for (int j=1;j<=p2;j++) {
			if (p3 == 2) out = c + out;
			else out += c;
		}
	}
	return out;
}
int main(){
	int p1,p2,p3;
	cin >> p1 >> p2 >> p3;
	string s;
	cin >> s;
	string out;
	for (int i=0;i<s.length();i++){
		if (s[i] == '-' && s[i-1] != '\0' && s[i+1] != '\0' && s[i-1] != '-' && s[i+1] != '-' && ( IsCharacter(s[i-1]) == IsCharacter(s[i+1]) ) && s[i-1]<s[i+1] ) out += expand(s[i-1],s[i+1],p1,p2,p3);
		else out += s[i];
	}
	cout << out << endl;
	return 0;
}