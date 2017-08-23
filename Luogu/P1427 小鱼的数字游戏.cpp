#include <cstdio>
#include <stack>
using namespace std;
int main() {
	stack <int> s;
	int tmp;
	while(scanf("%d",&tmp) == 1 && tmp != 0) {
		s.push(tmp);
	}
	while(!s.empty()) {
		printf("%d ",s.top());
		s.pop();
	}
	return 0;
}