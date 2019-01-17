#include <bits/stdc++.h>
using namespace std;
char s[105];
long long dx[128];
long long dy[128];
pair <long long,long long> pos[105];
int main() {
	dx['U'] = 0 ;dy['U'] = 1;
	dx['D'] = 0 ;dy['D'] = -1;
	dx['L'] = -1;dy['L'] = 0;
	dx['R'] = 1 ;dy['R'] = 0;
	long long x,y;
	scanf("%lld%lld",&x,&y);
	scanf("%s",s+1);
	if (x == 0 && y == 0) {
		printf("Yes\n");
		return 0;
	}
	int len = strlen(s+1);
	pos[0] = {0,0};
	for (int i=1;i<=len;i++) pos[i] = {pos[i-1].first+dx[s[i]],pos[i-1].second+dy[s[i]]};
	long long dx = pos[len].first - pos[0].first;
	long long dy = pos[len].second - pos[0].second;
	for (int i=0;i<=len;i++) {
		if (pos[i].first == x && pos[i].second == y) {
			printf("Yes\n");
			return 0;
		}
		if ((x-pos[i].first) * dy == (y-pos[i].second) * dx) {
			if (dx != 0 && (x-pos[i].first) % dx != 0) continue;
			if (dy != 0 && (y-pos[i].second) % dy != 0) continue;
			if (dx * (x-pos[i].first) < 0) continue;
			if (dy * (y-pos[i].second) < 0) continue;
			if ((dx == 0) != ((x-pos[i].first) == 0)) continue;
			if ((dy == 0) != ((y-pos[i].second) == 0)) continue;
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}
