#include <iostream>
using namespace std;
int memory[1005];//queue
int qbegin = 0;
int qend = -1;
int cnt = 0;
int N,M;
bool lookup(int word){//true:in memory
	for (int i=qbegin;i<=qend;i++) if (memory[i] == word) return true;
	return false;
}
void addword(int word){
	if (qend - qbegin + 1 == M) qbegin++;
	memory[++qend] = word;
}
int main(){
	cin >> M >> N;
	for (int i=0;i<N;i++){
		int word;
		cin >> word;
		if (!lookup(word)){
			addword(word);
			cnt ++;
		}
	}
	cout << cnt << endl;
	return 0;

}