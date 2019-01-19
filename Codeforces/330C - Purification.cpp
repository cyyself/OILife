#include <bits/stdc++.h>
using namespace std;
char s[100][101];
int row_pos[100];
int col_pos[100];
int row_cnt[100];
int col_cnt[100];
int main() {
	int n;
	scanf("%d",&n);
	memset(row_pos,-1,sizeof(row_pos));
	memset(col_pos,-1,sizeof(col_pos));
	for (int i=0;i<n;i++) {
		scanf("%s",&s[i][0]);
		for (int j=0;j<n;j++) {
			if (s[i][j] == '.') {
				row_pos[i] = j;
				col_pos[j] = i;
			}
		}
	}
	bool flag_x = true;
	bool flag_y = true;
	for (int i=0;i<n;i++) if (row_pos[i] == -1) flag_x = false;
	for (int i=0;i<n;i++) if (col_pos[i] == -1) flag_y = false;
	if (flag_x || flag_y) {
		if (flag_x) {
			for (int i=0;i<n;i++) printf("%d %d\n",i+1,row_pos[i]+1);
		}
		else {
			for (int i=0;i<n;i++) printf("%d %d\n",col_pos[i]+1,i+1);
		}
	}
	else puts("-1");
	return 0;
}
