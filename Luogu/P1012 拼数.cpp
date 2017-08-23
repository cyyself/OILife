#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
bool comp(string a,string b){
	return a+b > b+a;
}
int main(){
	int n;
	string a[20];
	cin >> n;
	for (int i=0;i<n;i++) cin >> a[i];
	sort(a,a+n,comp);
	for (int i=0;i<n;i++) cout << a[i];
	return 0;
}