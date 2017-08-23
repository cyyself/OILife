#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
int main(){
	string word;
	cin >> word;
	for (int i=0;i<word.length();i++) if (word[i]>=65 && word[i] < 97) word[i] += 32;
	string sentense;
	string separator = " ";
	cin.get();
	getline(cin,sentense);
	int cnt = 0;
	int ans = -1;
	for (int i=0;i<sentense.length();i++) if (sentense[i]>=65 && sentense[i] < 97) sentense[i] += 32;
	for (int i=0;i<sentense.length();i++){
		if (sentense[i] == word[0] && (i == 0 || sentense[i-1] == ' ') && (i == sentense.length() - 1 || sentense[i+word.length()] == ' ')){
			bool match = true;
			for (int j=1;j<word.length();j++) if (sentense[i+j] != word[j]) match = false;
			if (match){
				cnt ++;
				if (ans == -1) ans = i;
			}
		}
	}
	if (ans == -1) cout << "-1" << endl;
	else cout << cnt << " " << ans << endl;
	return 0;
}