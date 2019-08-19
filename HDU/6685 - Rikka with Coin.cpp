#include <bits/stdc++.h>
using namespace std;
int w[105];
int main() {
    int T;
    scanf("%d",&T);
    while (T --) {
        int n;
        scanf("%d",&n);
        bool flag = true;
        int max100 = 0;
        for (int i=1;i<=n;i++) {
            scanf("%d",&w[i]);
            max100 = max(max100,w[i] / 100);
            if (w[i] % 10 != 0) flag = false;
        }
        if (!flag) printf("-1\n");
        else {
            int ans = 0x3f3f3f3f;
            for (int c10=0;c10<=1;c10++) for (int c20=0;c20<=4;c20++) for (int c50=0;c50<=1;c50++) for (int c100=max(max100-1,0);c100<=max100;c100++) {
                bool avail[21];
                memset(avail,false,sizeof(avail));
                avail[0] = true;
                for (int i=0;i<c10;i++) for (int j=20;j>=1;j--) avail[j] |= avail[j-1];
                for (int i=0;i<c20;i++) for (int j=20;j>=2;j--) avail[j] |= avail[j-2];
                for (int i=0;i<c50;i++) for (int j=20;j>=5;j--) avail[j] |= avail[j-5];
                bool ok = true;
                for (int i=1;i<=n && ok;i++) {
                    int x = w[i];
                    bool cur[2] = {true,true};
                    int d100 = min(x/100,c100);
                    x -= d100 * 100;
                    if (x > 200) cur[0] = false;
                    else {
                        if (!avail[x/10]) cur[0] = false;
                    }
                    x = w[i];
                    d100 = min(max(0,x/100-1),c100);
                    x -= d100 * 100;
                    if (x > 200) cur[1] = false;
                    else {
                        if (!avail[x/10]) cur[1] = false;
                    }
                    if (!cur[0] && !cur[1]) ok = false;
                }
                if (ok) ans = min(ans,c10+c20+c50+c100);
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
