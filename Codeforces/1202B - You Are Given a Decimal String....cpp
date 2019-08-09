#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int mem[10][10][10][10];
void init() {
	for (int x=0;x<=9;x++) {
		for (int y=0;y<=9;y++) {
			for (int u=0;u<=9;u++) {
				for (int v=0;v<=9;v++) {
					for (int xc=0;xc<=9;xc++) {
						for (int yc=0;yc<=9;yc++) {
							if (xc == 0 && yc == 0) continue;
							if ((u + x * xc + y * yc) % 10 == v) {
								mem[x][y][u][v] = min(mem[x][y][u][v],xc+yc);
							}
						}
					}
				}
			}
		}
	}
}
char s[2000005];
int main() {
	memset(mem,0x3f,sizeof(mem));
	init();
	scanf("%s",s);
	for (int x=0;x<=9;x++) {
		for (int y=0;y<=9;y++) {
			long long ans = 0;
			for (int i=0;s[i+1] != 0;i++) {
				if (mem[x][y][s[i]-'0'][s[i+1]-'0'] == INF) {
					ans = -1;
					break;
				}
				ans += mem[x][y][s[i]-'0'][s[i+1]-'0'] - 1;
			}
			printf("%lld ",ans);
		}
		printf("\n");
	}
	return 0;
}
