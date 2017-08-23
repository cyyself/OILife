#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
bool used[10];
int num;
int n;
struct d{
	int a;
	int b;
};
d newd(int a,int b){
	d t;
	t.a = a;
	t.b = b;
	return t;
}
vector <d> ans;
int layer;
bool check(int num){
	if (num < 1000) return false;
	bool tused[10];
	memset(tused,0,sizeof(tused));
	if (num < 10000) {
		if (used[0]) return false;
		tused[0] = true;
	}
	while(true){
		if (num == 0) break;
		int t = num % 10;
		if (used[t] || tused[t]) return false;
		else {
			tused[t] = true;
			num /= 10;
		}
	}
	return true;
}
void gennum(int layer){
	if (layer == 5){
		if (check(num*n)) ans.push_back(newd(num*n,num));
	}
	else{
		for (int i=0;i<=9;i++){
			if (!used[i]){
				num += i * pow(10,layer);
				used[i] = true;
				gennum(layer+1);
				num -= i * pow(10,layer);
				used[i] = false;
			}
		}
	}
}
bool comp(d a,d b){
	if (a.a < b.a) return true;
	return false;
}
int main(){
	bool first = true;
	for(;;){
		scanf("%d",&n);
		if (n == 0) break;
		if (!first) printf("\n");
		first = false;
		memset(used,0,sizeof(used));
		num = 0;
		ans.clear();
		gennum(0);
		if (ans.empty()) printf("There are no solutions for %d.\n",n);
		else{
			sort(ans.begin(),ans.end(),comp);
			for (int i=0;i<ans.size();i++){
				if (ans[i].b < 10000) printf("%d / 0%d = %d\n",ans[i].a,ans[i].b,n);
				else printf("%d / %d = %d\n",ans[i].a,ans[i].b,n);
			}
		}
	}
	return 0;
}