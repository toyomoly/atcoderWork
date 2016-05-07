#include <iostream>
using namespace std;
int main()
{
    int H, W;
    cin >> H >> W;
    
    int A[W][H];
    
    for (int x=0; x<W; x++) {
        for (int y=0; y<H; y++) {
            int a;
            cin >> a;
            A[x][y] = a;
        }
    }
    
    int sum;
    
    for (int x=0; x<W; x++) {
        for (int y=0; y<H; y++) {
            // 頂上を見つける
            if (
                ((x == 0) || (A[x][y] > A[x-1][y]))
                && ((x == W-1) || (A[x][y] > A[x+1][y]))
                && ((y == 0) || (A[x][y] > A[x][y-1]))
                && ((y == H-1) || (A[x][y] > A[x][y+1]))
                ) {
                // その頂点からの下る経路
                
                
                
                sum += 0;
            }
        }
    }
    
    cout << sum << endl;
    return 0;
}