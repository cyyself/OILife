#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int s[7];
int main() {
	while (true) {
		bool flag = false;
		for (int i=1;i<=6;i++) {
			scanf("%d",&s[i]);
			if (s[i] != 0) flag = true;
		}
		if (!flag) break;
		long long ans = s[6];

		//装5的箱子装5和1
		ans += s[5];
		s[1] -= min(s[1],11*s[5]);

		//装4的箱子装4、2、1
		ans += s[4];
		int sz = 6 * 6 * s[4] - 4 * 4 * s[4];
		int avail2 = min(s[2],5*s[4]);
		s[2] -= avail2;
		sz -= 4 * avail2;
		s[1] -= min(s[1],sz);

		//装3的箱子装3、2、1
		ans += ceil(s[3] / 4.0);
		if (s[3] % 4 != 0) {//感觉会有挺多人WA在这个0没判的时候
			switch (s[3] % 4) {
				case 1:
					//可以装5个2*2，7个1*1，2*2不满就另外补
					sz = 6 * 6 - 3 * 3;
					sz -= 2 * 2 * min(5,s[2]);
					s[2] -= min(5,s[2]);

					s[1] -= min(s[1],sz);
					break;
				case 2:
					//可以装3个2*2，6个1*1
					sz = 6 * 6 - 2 * 3 * 3;
					sz -= 2 * 2 * min(3,s[2]);
					s[2] -= min(3,s[2]);

					s[1] -= min(s[1],sz);
					break;
				case 3:
					//可以装1个2*2，5个1*1
					sz = 6 * 6 - 3 * 3 * 3;
					sz -= 2*2 * min(1,s[2]);
					s[2] -= min(1,s[2]);

					s[1] -= min(s[1],sz);
			}
		}


		//装2的箱子就装1、2了
		ans += ceil(s[2] / 9.0);
		if (s[2] % 9 != 0) {
			sz = 6 * 6 - 2 * 2 * (s[2] % 9);
			s[1] -= min(s[1],sz);
		}

		//就剩下1了
		ans += ceil(s[1] / 36.0);

		printf("%lld\n",ans);
	}
	return 0;
}
