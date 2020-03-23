#include <bits/stdc++.h>
using namespace std;
vector <char> buf;
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) buf.push_back('U');
	for (int i=0;i<m;i++) buf.push_back('L');
	for (int i=0;i<n;i++) {
		if ((i & 1) == 0) for (int j=0;j<m-1;j++) buf.push_back('R');
		else for (int j=0;j<m-1;j++) buf.push_back('L');
		if (i != n-1) buf.push_back('D');
	}
	printf("%d\n",(int)buf.size());
	for (auto c:buf) printf("%c",c);
	printf("\n");
	return 0;
}
