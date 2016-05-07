#include <iostream>
using namespace std;

int H, W;
int A[1002][1002];
int cash[1002][1002];
int mod = 1000000007;

int count(int x, int y) {
    
    int sum = 1;
    
    if (cash[x][y] > 0) {
        return cash[x][y];
    }
    
    if (A[x][y] < A[x-1][y]) {
        sum += count(x-1, y);
    }
    if (A[x][y] < A[x+1][y]) {
        sum += count(x+1, y);
    }
    if (A[x][y] < A[x][y-1]) {
        sum += count(x, y-1);
    }
    if (A[x][y] < A[x][y+1]) {
        sum += count(x, y+1);
    }
    cash[x][y] = sum;
    
    return sum;
}

int main()
{
    memset(cash, 0, 1002 * 1002 * 4);
    cin >> H >> W;
    
    for (int y=0; y<H; y++) {
        for (int x=0; x<W; x++) {
            scanf("%d", &A[x+1][y+1]);
        }
    }
    
    unsigned long sum = 0;
    
    for (int x=0; x<W; x++) {
        for (int y=0; y<H; y++) {
            sum += count(x+1, y+1);
            sum %= mod;
        }
    }
    
    cout << sum << endl;
    return 0;
}