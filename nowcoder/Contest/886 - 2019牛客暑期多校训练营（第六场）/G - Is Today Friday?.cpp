#include <bits/stdc++.h>
using namespace std;
bool friday[10000][13][32];
inline bool runnian(int y) {
    return (y % 100 != 0 && y % 4 == 0) || (y % 400 == 0);
}
void init() {
    int md[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int cur = 5;
    for (int y=1600;y<=9999;y++) {
        md[2] = runnian(y)?29:28;
        for (int m=1;m<=12;m++) for (int d=1;d<=md[m];d++) {
            cur ++;
            cur %= 7;
            if (cur == 5) friday[y][m][d] = true;
        }
    }
}
string s[100000];
int main() {
    init();
    int T;
    cin >> T;
    //scanf("%d",&T);
    for (int cas=1;cas<=T;cas++) {
        int n;
        cin >> n;
        //scanf("%d",&n);
        for (int i=0;i<n;i++) cin >> s[i];
        sort(s,s+n);
        n = unique(s,s+n) - s;
        int ans[10] = {0,1,2,3,4,5,6,7,8,9};
        bool exist = false;
        do {
            bool flag = true;
            for (int i=0;i<n;i++) {
                int y = ans[s[i][0]-'A'] * 1000 + ans[s[i][1]-'A'] * 100 + ans[s[i][2]-'A'] * 10 + + ans[s[i][3]-'A'];
                int m = ans[s[i][5]-'A'] * 10 + ans[s[i][6]-'A'];
                int d = ans[s[i][8]-'A'] * 10 + ans[s[i][9]-'A'];
                if (y < 1600 || y > 9999 || m < 1 || m > 12 || d < 1 || d > 31 || !friday[y][m][d]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                exist = true;
                printf("Case #%d: ",cas);
                for (int i=0;i<10;i++) printf("%d",ans[i]);
                printf("\n");
                break;
            }
        }
        while (next_permutation(ans,ans+10));
        if (!exist) printf("Case #%d: Impossible\n",cas);
    }
    return 0;
}
