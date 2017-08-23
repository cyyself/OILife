#include <cstdio>
using namespace std;
int main(){
  int array[10];
  for (int i=0;i<10;i++){
    scanf("%d",&array[i]);
  }
  int height;
  scanf("%d",&height);
  height += 30;
  int ans = 0;
  for (int i=0;i<10;i++){
    if (array[i] <= height) ans++;
  }
  printf("%d\n",ans);
  return 0;
}