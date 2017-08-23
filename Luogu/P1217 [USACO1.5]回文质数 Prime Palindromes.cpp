#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int tot = 0;
bool judge(int x) {
	if (x == 0) return false;
	for (long long i=2;i*i<=x;i++) if (x % i == 0) return false;
	return true;
}
int cnt = 0;
long long a,b;
vector <long long> ans;
long long atol(char *a) {
	long long ret = 0;
	while (*a != 0) {
		ret *= 10;
		ret += *a - 48;
	}
	return ret;
}
void DFS(string cur) {
	if (cur.length() != 0) {
		string hw[2] = {
			cur,
			cur
		};
		for (int i=cur.length()-1;i>=0;i--) hw[0] += cur[i];
		for (int i=cur.length()-2;i>=0;i--) hw[1] += cur[i];
		
		long long ha = atol(hw[0].c_str());
		long long hb = atol(hw[1].c_str());

		if (ha >= a && ha <= b) if (judge(ha)) ans.push_back(ha);
		if (hb >= a && hb <= b) if (judge(hb)) ans.push_back(hb);

		if (ha <= b || hb <= b) for (int i=0;i<=9;i++) DFS(cur+char('0'+i));
	}
	else {
		for (int i=1;i<=9;i++) DFS(cur+char('0'+i));
	}
	
}
int main() {
	scanf("%lld%lld",&a,&b);
	DFS("");
	sort(ans.begin(),ans.end());
	for (vector<long long>::iterator iter=ans.begin();iter != ans.end();iter++) printf("%lld\n",*iter);
	
	return 0;
}