#include <bits/stdc++.h>
using namespace std;
bool cunzai[256];
struct shuju {
	char c;
	bool enter;
	int d;
	shuju (char _c,bool _enter,int _d) {
		c = _c;
		enter = _enter;
		d = _d;
	}
};
stack<shuju> s;
int getfzd() {
	char c = getchar();
	while (c != '(') {
		c = getchar();
	}
	c = getchar();//n
	if (c == 'n') {
		c = getchar();//^
		c = getchar();
		int ret = 0;
		while (c >= '0' && c <= '9'){
			ret *= 10;
			ret += c - '0';
			c = getchar();
		}
		return ret;
	}
	else {
		//1
		c = getchar();//)
		return 0;
	}
}
int stoint(string s) {
	int ret = 0;
	for (unsigned int i=0;i<s.length();i++) {
		ret *= 10;
		ret += s[i] - '0';
	}
	return ret;
}
int main() {
	int t;
	scanf("%d",&t);
	while (t--) {
		while (!s.empty()) s.pop();
		int L;
		scanf("%d",&L);
		int fzd = getfzd();
		memset(cunzai,false,sizeof(cunzai));
		bool err = false;
		int ans = 0;
		while (L--) {
			char flag;
			cin >> flag;
			if (flag == 'E') {
				if (!s.empty()) {
					shuju cur = s.top();
					cunzai[cur.c] = false;
					s.pop();
					if (cur.enter) {
						ans = max(ans,cur.d);
					}
				}
				else err = true;
			}
			else {
				bool enter = true;
				int curd = 0;
				if (!s.empty()) {
					shuju cur = s.top();
					enter = cur.enter;
					curd = cur.d;
				}
				char bianliang;
				cin >> bianliang;
				if (cunzai[bianliang]) err = true;
				cunzai[bianliang] = true;
				string x;
				string y;
				cin >> x;
				cin >> y;
				if (x == "n") {
					if (y != "n") enter = false;
				}
				else {
					if (y == "n") curd += 1;
					else {
						int qidian = stoint(x);
						int zhongdian = stoint(y);
						if (qidian > zhongdian) enter = false; 
					}
				}
				s.push(shuju(bianliang,enter,curd));
			}
		}
		if (err || !s.empty()) printf("ERR\n");
		else if (ans == fzd) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
