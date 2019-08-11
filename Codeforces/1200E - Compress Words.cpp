#include <bits/stdc++.h>
using namespace std;
vector <string> vec;
char buf[1000005];
int buflen;
int kmp[1000005];
void getnext(string &P) {
	kmp[0] = -1;
	int k = -1;
	for (int i=1;i<P.length();i++) {
		while (k != -1 && P[i] != P[k+1]) k = kmp[k];
		if (P[i] == P[k+1]) k ++;
		kmp[i] = k;
	}
}
int getlastk(int st,string &P) {
	int k = -1;
	for (int i=st;i<buflen;i++) {
		while (k != -1 && buf[i] != P[k+1]) k = kmp[k];
		if (buf[i] == P[k+1]) k++;
	}
	return k;
}
int main() {
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		string t;
		cin >> t;
		vec.push_back(t);
	}
	for (auto c:vec[0]) buf[buflen++] = c;
	for (int i=1;i<n;i++) {
		getnext(vec[i]);
		int lastk = getlastk(buflen-vec[i].length(),vec[i]);
		for (int j=lastk+1;j<vec[i].length();j++) buf[buflen++] = vec[i][j];
	}
	buf[buflen] = 0;
	printf("%s\n",buf);
	return 0;
}
