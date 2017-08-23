#include <iostream>
using namespace std;
int main(){
	string a;//密字
	string b;//原文
	string c;//要解密的信息
	char map[128]={0};//map[密文字符]=明文字符
	char cmap[128]={0};//cmap[明文字符]=密文字符
	cin >> a >> b >> c;
	for (int i=0;i<a.length();i++){
		if(map[a[i]] == '\0') map[a[i]] = b[i];
		else if(map[a[i]] != b[i]){
			cout << "Failed" << endl;//一个密文字符对应了多个明文
			return 0;
		}
		if(cmap[b[i]] == '\0') cmap[b[i]] = a[i];
		else if(cmap[b[i]] != a[i]){
			cout << "Failed" << endl;//一个明文字符对应了多个密文
			return 0;
		}
	}
	for (char i='A';i<='Z';i++){
		if (map[i] == '\0') {
			cout << "Failed" << endl;//26个字母没有全部出现
			return 0;
		}
	}
	string r = "";
	for (int i=0;i<c.length();i++){
		if (map[c[i]] == '\0'){
			cout << "Failed" << endl;//有字符无法从密文找到明文
			return 0;
		}
		else r += map[c[i]];
	}
	cout << r << endl;
	return 0;

}