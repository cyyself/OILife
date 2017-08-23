#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
char map[205][205];//0:洞 1:图案黑色部分 2:图的空白部分或已访问部分
int H,W;
struct Pos{
	int x;
	int y;
};
Pos NewPos(int x,int y){
	Pos t;
	t.x = x;
	t.y = y;
	return t;
}
const char zero[] = {'0','\0'};
const char label[16][5]={
	{'0','0','0','0','\0'},
	{'0','0','0','1','\0'},
	{'0','0','1','0','\0'},
	{'0','0','1','1','\0'},
	{'0','1','0','0','\0'},
	{'0','1','0','1','\0'},
	{'0','1','1','0','\0'},
	{'0','1','1','1','\0'},
	{'1','0','0','0','\0'},
	{'1','0','0','1','\0'},
	{'1','0','1','0','\0'},
	{'1','0','1','1','\0'},
	{'1','1','0','0','\0'},
	{'1','1','0','1','\0'},
	{'1','1','1','0','\0'},
	{'1','1','1','1','\0'}
};
const int nx[] = {0,-1,0,1};
const int ny[] = {1,0,-1,0};
const char hole[]={'W','A','K','J','S','D'};
void convertto2(char c, char * r){
	if (c >= 48 && c <=57) strcat(r,label[c-48]);
	else if (c >= 97) strcat(r,label[c-97+10]);
}
void fillchar(Pos p, char value){
	queue <Pos> q;
	q.push(p);
	while(!q.empty()){
		Pos now = q.front();
		q.pop();
		for (int i=0;i<4;i++){
			int x = now.x + nx[i];
			int y = now.y + ny[i];
			if (x < 0 || y < 0 || x > H+1 || y > 4*W+1) continue;
			if (map[x][y] == '0'){
				map[x][y] = value;
				q.push(NewPos(x,y));
			}
		}
	}
}
int counthole(Pos p){
	int cnt = 0;
	queue <Pos> q;
	q.push(p);
	map[p.x][p.y] = '2';
	while(!q.empty()){
		Pos now = q.front();
		q.pop();
		for (int i=0;i<4;i++){
			int x = now.x + nx[i];
			int y = now.y + ny[i];
			if (x < 0 || y < 0 || x > H+1 || y > 4*W+1) continue;
			if (map[x][y] == '1'){
				q.push(NewPos(x,y));
				map[x][y] = '2';
			}
			else if (map[x][y] == '0'){
				cnt ++;
				fillchar(NewPos(x,y),'2');
			}
		}
	}
	return cnt;
}
int main(){
	int n = 0;
	for (;;){
		cin >> H >> W;
		if (H == 0 && W == 0) break;
		n ++;
		cin.get();
		memset(map,0,sizeof(map));
		memset(map[0],'0',4*W+2);
		for (int i=1;i<=H;i++){
			map[i][0] = '0';
			char t[51] = {0};
			cin.getline(t,W+1);
			for (int j=0;j<strlen(t);j++) convertto2(t[j],&map[i][1]);
			strcat(map[i],zero);
		}
		memset(map[H+1],'0',4*W+2);
		fillchar(NewPos(0,0),'2');
		cout << "Case " << n << ": ";
		string output = "";
		for (int i=1;i<=4*W;i++) for (int j=1;j<=H;j++) if (map[j][i] == '1') output += hole[counthole(NewPos(j,i))];
		sort(output.begin(),output.end());
		cout << output << endl;
	}
	return 0;
}