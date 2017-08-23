#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
bool map[32][32];
int p;
void draw(int xb,int xe,int yb,int ye){//x-begin,x-end,y-begin,y-end
	for (int x=xb;x<xe;x++)
		for (int y=yb;y<ye;y++) map[x][y] = true;
}
void judge(string s,int layer,int x,int y){//p代表当前所读取的位置
	if (p == 0){
		if (s[0] == 'f') draw(0,32,0,32);
		if (s[0] == 'p'){
			p++;
			judge(s,layer+1,0,0);
		}
	}
	else{//非第一层的情况
		int next = 32 / pow(2,layer);
		int midx = x + next;
		int midy = y + next;
		int tailx = midx + next;
		int taily = midy + next;
		//第一象限
		if (s[p] == 'p') {
			p++;
			judge(s,layer+1,midx,y);
		}else{
			if (s[p] == 'f') draw(midx,tailx,y,midy);
			p++;
		}
		//第二象限
		if (s[p] == 'p') {
			p++;
			judge(s,layer+1,x,y);
		}else{
			if (s[p] == 'f') draw(x,midx,y,midy);
			p++;
		}
		//第三象限
		if (s[p] == 'p') {
			p++;
			judge(s,layer+1,x,midy);
		}else{
			if (s[p] == 'f') draw(x,midx,midy,taily);
			p++;
		}
		//第四象限
		if (s[p] == 'p') {
			p++;
			judge(s,layer+1,midx,midy);
		}else{
			if (s[p] == 'f') draw(midx,tailx,midy,taily);
			p++;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	cin.get();
	for (int i=0;i<n;i++){
		memset(map,0,sizeof(map));
		string a,b;
		getline(cin,a);
		getline(cin,b);
		p = 0;
		judge(a,0,0,0);
		p=0;
		judge(b,0,0,0);
		//统计方块数
		int cnt = 0;
		for (int j=0;j<32;j++)
			for (int k=0;k<32;k++)
				if (map[j][k]) cnt ++;
		printf("There are %d black pixels.\n",cnt);
	}
}