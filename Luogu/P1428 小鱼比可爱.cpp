#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int fish[101];
    for(int i=0;i<n;i++){
        int score=0;
        cin >> fish[i];
        for(int j=i;j>=0;j--) if(fish[i] > fish[j]) score++;
        cout << score << " ";
    }
    cout << endl;
    return 0;
}