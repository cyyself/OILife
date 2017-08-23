#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int dirx[4] = {1,0,-1,0};
const int diry[4] = {0,1,0,-1};
int n;
int main(){
	int x,y;
	cin >> n >> y >> x;
	int start[30005];
	start[0] = 0;
	for (int i=1;i<=ceil(n/2);i++) start[i] = start[i-1] + 4 * (n-(i-1)*2) - 4;//算出每圈起始点的数值
	if (n % 2 == 1) start[int(ceil(n/2)+1)] = start[int(ceil(n/2))] + 1;
	int quan = min(min(x-1,n-x),min(y-1,n-y));//第几圈
	int nowx = quan - 1;//计算该圈的起始位置
	int nowy = quan;
	//我们发现，直接模拟该题过程时，同一方向走的步数为n,n-1,n-1,n-2,n-2,n-3,n-3一直到1
	//以下过程大家自己在草稿纸上模拟就懂了，自己模拟时把nowx改为-1，nowy改为0效果更佳
	int cnt = 1;//同种步数走两次，但是步数为n时只走一次，所以初始值是1，后面清零后是0
	int step = n - quan * 2;//这一方向要走的step
	int stepnow = 0;//这一方向当前走的步数
	int dir = 0;//方向
	for (int i=start[quan]+1;i<=start[quan+1];i++){
        nowx += dirx[dir];
        nowy += diry[dir];
        stepnow++;
        if (nowx == x - 1 && nowy == y - 1){
            cout << i << endl;
            return 0;
        }
        if (stepnow == step) {
            cnt ++;
            dir ++;
            stepnow = 0;
        }
        if (dir == 4) dir = 0;
        if (cnt == 2){
            step--;
            cnt = 0;
        }
	}
	return 0;
}