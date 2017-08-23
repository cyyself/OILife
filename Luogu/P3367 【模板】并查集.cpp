#include <cstdio>
using namespace std;
int family[10005];
int find(int x){
    if (family[x] == x) return x;
    else {
        family[x] = find(family[x]);//记忆化
        return family[x];
    }
}
int main(){
    int N,M;
    scanf("%d%d",&N,&M);
    for (int i=1;i<=N;i++) family[i] = i;
    for (int i=1;i<=M;i++){
        int Zi,Xi,Yi;
        scanf("%d%d%d",&Zi,&Xi,&Yi);
        if (Zi == 1) {
            family[find(Xi)] = find(Yi);
        }
        else {
            if (family[find(Xi)] == family[find(Yi)]) printf("Y\n");
            else printf("N\n");
        }
    }
    return 0;
}