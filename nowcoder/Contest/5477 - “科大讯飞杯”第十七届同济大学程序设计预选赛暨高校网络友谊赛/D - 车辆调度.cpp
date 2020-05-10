#include <bits/stdc++.h>
using namespace std;
vector < vector<pair<int,int> > > to_chk;
int r;
void dfs(int dep,vector<pair<int,int> >seq) {
    if (dep == 0) {
        to_chk.push_back(seq);
        return;
    }
    for (int i=0;i<r;i++) {
        for (int dir=0;dir<4;dir++) {
            auto nxt_seq = seq;
            nxt_seq.emplace_back(i,dir);
            dfs(dep-1,nxt_seq);
        }
    }
}
set <pair<int,int> > dst;
char mp[10][11];
int m,n;
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};
bool chk(vector<pair<int,int> > &seq) {
    char cmp[10][11];
    memcpy(cmp,mp,sizeof(mp));
    vector <pair <int,int> > rpos;
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) if (cmp[i][j] == 'R') rpos.emplace_back(i,j);
    for (auto cmd:seq) {
        int &x = rpos[cmd.first].first;
        int &y = rpos[cmd.first].second;
        int nx = x + dx[cmd.second];
        int ny = y + dy[cmd.second];
        while ((nx >= 0 && ny >= 0 && nx < n && ny < m) && (cmp[nx][ny] == '.')) {
            swap(cmp[x][y],cmp[nx][ny]);
            x = nx;
            y = ny;
            nx = x + dx[cmd.second];
            ny = y + dy[cmd.second];
        }
    }
    for (auto x:rpos) {
        if (dst.count(x)) return true;
    }
    return false;
}
int main() {
    int k;
    scanf("%d%d%d",&m,&n,&k);
    for (int i=0;i<n;i++) {
        scanf("%s",&mp[i][0]);
        for (int j=0;j<m;j++) {
            if (mp[i][j] == 'R') r ++;
            else if (mp[i][j] == 'D') {
                dst.insert({i,j});
                mp[i][j] = '.';
            }
        }
    }
    vector <pair<int,int> > emp;
    dfs(k,emp);
    bool ans = false;
    for (auto seq:to_chk) if (chk(seq)) {
        ans = true;
        break;
    }
    if (ans) printf("YES\n");
    else printf("NO\n");
    return 0;
}
