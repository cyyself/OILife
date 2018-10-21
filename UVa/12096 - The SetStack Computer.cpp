#include <bits/stdc++.h>
using namespace std;
map <set<int>,int> shash;
map <int,set<int> > rshash;
int cnt = 1;
inline int getnum(const set<int> &a) {
	if (shash[a] == 0) {
		shash[a] = cnt;
		rshash[cnt] = a;
		cnt ++;
	}
	return shash[a];
}
inline set<int> uni(const set<int> &a,const set<int> &b) {
	set<int> ret;
	set_union(a.begin(),a.end(),b.begin(),b.end(),inserter(ret,ret.begin()));
	return ret;
}
inline set<int> ins(const set<int> &a,const set<int> &b) {
	set<int> ret;
	set_intersection(a.begin(),a.end(),b.begin(),b.end(),inserter(ret,ret.begin()));
	return ret;
}
set<int> empty_set;
int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n;
		scanf("%d",&n);
		stack <int> s;
		while (n --) {
			char cmd[15];
			scanf("%s",cmd);
			int e = 0;
			switch (cmd[0]) {
				case 'P':
					//PUSH
					s.push(getnum(empty_set));
					break;
				case 'D':
					//DUP
					s.push(s.top());
					break;
				case 'U':
					//UNION
					{
						int a = s.top();
						s.pop();
						int b = s.top();
						s.pop();
						s.push(getnum(uni(rshash[a],rshash[b])));
					}
					break;
				case 'I':
					//INTERSECT
					{
						int a = s.top();
						s.pop();
						int b = s.top();
						s.pop();
						s.push(getnum(ins(rshash[a],rshash[b])));
					}
					break;
				case 'A':
					//ADD
					{
						int a = s.top();
						s.pop();
						int b = s.top();
						s.pop();
						set <int> t = rshash[b];
						t.insert(a);
						s.push(getnum(t));
					}
					break;
			}
			printf("%lu\n",rshash[s.top()].size());
		}
		printf("***\n");
	}
	return 0;
}
