#include <cstdio>
using namespace std;
//不得不吐槽一下出题人，明明就是把一些花移走使剩下的花一大一小或者一小一大排列。却把题目公式写的这么复杂。
int main(){
	int n;
	scanf("%d",&n);
	int h[100005];
	for (int i=0;i<n;i++) scanf("%d",&h[i]);
	int max = 0;
	for (int i=0;i<n;i++){
		int t = 1;
		int s = 0;//上次status，-1:小，0：初始状态，1:大
		for (int j=n-2;j>=i;j--){
			if (h[j] > h[j+1] && s != 1){
				t++;
				s = 1;
			}
			else if (h[j] < h[j+1] && s != -1){
				t ++;
				s = -1;
			}
		}
		if (t > max) max = t;
		else if (t < max) break;
	}
	printf("%d\n",max);
	return 0;
}