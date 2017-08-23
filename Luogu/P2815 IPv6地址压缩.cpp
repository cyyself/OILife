#include <iostream>
using namespace std;
string compress(string address){//输入地址必须是全展开IPv6地址
	address += ':';
	string p[8];//每次处理后的输出变量
	//化简0
	string t;//临时处理变量
	int cnt = 0;
	for (int i=0;i<address.length();i++){
		if (address[i] == ':') {
			if (t != "") {
				p[cnt] += t;
				t = "";
			}
			else p[cnt] = "0";
			cnt ++;
		}
		else {
			if ( (address[i] == '0' && t != "") || address[i] != '0') t += address[i];
		}
	}
	//压缩全0部分
	int complen[8]={0};//全0长度
	for (int i=0;i<8;i++){
		for (int j=i;j<8;j++) if (p[j] == "0") complen[i]++;
		else break;
	}
	int compp = 0;
	for (int i=0;i<8;i++){
		if (complen[i] > complen[compp]) compp = i;
	}
	//输出
	string out;
	for (int i=0;i<8;i++){
		if ( (i == compp && complen[compp] != 0)){
			if (out.length() == 0 || out[out.length()-1] != ':') out +=":";
			out +=":";
		}
		else if ( !(i > compp && i < compp + complen[compp]) ) {
			out +=p[i];
			if (i != 7) out += ":";//不是最后一个就要加:分割
		}
	}
	return out;
}
int main(){
	string ip;
	cin >> ip;
	cout << compress(ip) << endl;
	return 0;
}
