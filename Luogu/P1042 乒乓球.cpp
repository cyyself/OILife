#include <iostream>
#include <cmath>
using namespace std;
int main(){
	string comp;
	string t;
	while(cin >> t) comp += t;
	//处理11分情况
	int W=0,L=0,cnt;
	bool end = false;
	for (int i=0;i<comp.length() && !end;i++){
		cnt ++;
		switch(comp[i]){
			case 'W':
				W++;
				break;
			case 'L':
				L++;
				break;
			case 'E':
				//end=true;
				cnt --;
				break;
		}
		if ( (W >= 11 || L >= 11) && abs(W - L) >= 2 ){
			cout << W << ":" << L << endl;
			cnt = 0;
			W = 0;
			L = 0;
		}
	}
	if (cnt != 0){
		cout << W << ":" << L << endl;
	}
	end = false;
	W = 0;
	L = 0;
	cout << endl;
	for (int i=0;i<comp.length() && !end;i++){
		cnt ++;
		switch(comp[i]){
			case 'W':
				W++;
				break;
			case 'L':
				L++;
				break;
				
			case 'E':
				//end = true;
				cnt--;
				break;
				
		}
		if ( (W >= 21 || L >= 21) && abs(W-L) >= 2){
			cout << W << ":" << L << endl;
			cnt = 0;
			W = 0;
			L = 0;
		}
	}
	if (cnt != 0){
		cout << W << ":" << L << endl;
	}
	return 0;
}