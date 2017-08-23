#include <cstdio>
using namespace std;
int father[5005];
int find(int x){
    if (father[x] == x) return x;
    else return find(father[x]);
}
int main(){
    int n,m,p;
    scanf("%d%d%d",&n,&m,&p);
    for (int i=1;i<=n;i++){
        father[i] = i;
    }
    for (int i=1;i<=m;i++){
        int Mi,Mj;
        scanf("%d%d",&Mi,&Mj);
        father[find(Mi)] = find(Mj);
    }
    for (int i=1;i<=p;i++){
        int Pi,Pj;
        scanf("%d%d",&Pi,&Pj);
        if (find(Pi) == find(Pj)) printf("Yes\n");
        else printf("No\n");
    }
}