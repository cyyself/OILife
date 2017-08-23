#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int L,N;
	cin >> L >> N;
	int mi = 0,ma = 0;//mi=min,ma=max
	for (int i=0;i<N;i++){
		int soldier;
		cin >> soldier;
		mi=max(mi,min(L + 1 - soldier,soldier));
		ma=max(ma,max(L + 1 - soldier,soldier));
	}
	cout << mi << " " << ma << endl;
	return 0;
}