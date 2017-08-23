#include <cstdio>
using namespace std;
int main(){
	char ISBN[20];
	scanf("%s",&ISBN[0]);
	int t = 0;
	int p = 0;
	for (int i=0;i<12;i++){
		if (ISBN[i] != '-'){
			p ++;
			t += (ISBN[i]-48)*p;
		}
	}
	t = t % 11;
	if (t == 10){
		if (ISBN[12] == 'X') printf("Right");
		else {
			ISBN[12] = 'X';
			printf("%s",ISBN);
		}
	}
	else{
		if (ISBN[12] == t + 48) printf("Right");
		else{
			ISBN[12] = t + 48;
			printf("%s",ISBN);
		}
	}
	return 0;
}