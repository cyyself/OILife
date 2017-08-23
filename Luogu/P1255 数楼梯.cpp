#include <iostream>
using namespace std;
string sum(string x, string y){
	string nx;
	string ny;
	for (int i=x.length()-1;i>=0;i--) nx += x[i]-48;
	for (int i=y.length()-1;i>=0;i--) ny += y[i]-48;
	//翻转数字
	string result;
	int add = 0;
	bool longer;//为true时x大于y
	if (nx.length() > ny.length()) longer = true; else longer = false;
	for (int i=0;i<min(x.length(),y.length());i++){
		result += (nx[i]+ny[i]+add)%10;
		add = (nx[i]+ny[i]+add)/10;
	}
	for (int i=min(x.length(),y.length());i<max(nx.length(),ny.length());i++){
		if (longer){
			result += (nx[i] + add)%10;
			add = (nx[i] + add)/10;
		}
		else{
			result += (ny[i] + add)%10;
			add = (ny[i] + add)/10;
		}
	}
	if (add > 0) result += add;
	string final;
	bool zeroflag = false;//用于处理多余的0
	for (int i=result.length()-1;i>=0;i--){
		if (result[i] == 0) {
			if (!zeroflag && i != 0) continue;
		}
		else zeroflag = true;
		final += result[i]+48;
	}
	return final;
}
int main() {
	string fibo[5005];
	fibo[0] = "0";
	fibo[1] = "1";
	fibo[2] = "2";
	int n;
	cin >> n;
	for (int i=3;i<=n;i++) fibo[i] = sum(fibo[i-1],fibo[i-2]);
	cout << fibo[n] << endl;
	return 0;
}