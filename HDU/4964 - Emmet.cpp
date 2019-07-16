#include <bits/stdc++.h>
using namespace std;
string s;
const char m[3] = {'.','#','*'};
struct Tag {
	string name;
	string id;
	string cla;
	int times;
	int scan(int idx) {
		name = "";
		id = "";
		cla = "";
		times = 0;
		int mode = 0;
		while (idx < s.length() && s[idx] != '>' && s[idx] != ')') {
			for (int i=0;i<3;i++) {
				if (m[i] == s[idx]) {
					mode = i + 1;
					idx ++;
					continue;
				}
			}
			string tmp;
			while (idx < s.length() && s[idx] != '>' && s[idx] != ')' && s[idx] != m[0] && s[idx] != m[1] && s[idx] != m[2]) {
				tmp += s[idx];
				idx ++;
			}
			if (mode == 0) name = tmp;
			else if (mode == 1) cla += (cla==""?"":" ") + tmp;
			else if (mode == 2) id = tmp;
			else if (mode == 3) for (auto c:tmp) times = times*10 + c - '0';
		}
		if (times == 0) times = 1;
		return idx + (s[idx]!=')'?1:0);
	}
	string output_s() {
		return "<" + name + (id==""?"":" id=\""+id+"\"") + (cla==""?"":" class=\""+cla+"\"") + ">";
	}
	string output_t() {
		return "</" + name + ">";
	}
}T;
struct DATA {
	string s,tag;
	int times;
};
pair<string,int> work(int _idx) {
	int idx = _idx;
	stack <DATA> st;
	while (idx < s.length() && s[idx] != '>' && s[idx] != ')') {
		if (s[idx] == '(') {
			auto tmp = work(idx+1);
			idx = tmp.second;
			st.push((DATA){tmp.first,"",1});
		}
		else {
			idx = T.scan(idx);
			st.push((DATA){T.output_s(),T.name,T.times});
		}
	}
	string ret = "";
	while (!st.empty()) {
		DATA cur = st.top();
		st.pop();
		ret = cur.s + ret + (cur.tag==""?"":"</"+cur.tag+">");
		if (cur.times != 1) {
			string tmp = ret;
			ret = "";
			for (int i=0;i<cur.times;i++) ret += tmp;
		}
	}
	return make_pair(ret,idx+1);
}
int main() {
	int n;
	scanf("%d",&n);
	getline(cin,s);
	while (n --) {
		getline(cin,s);
		auto ans = work(0);
		cout << ans.first << endl;
	}
	return 0;
}
