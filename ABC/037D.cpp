#include <iostream>
using namespace std;

int H, W;
int A[1000][1000];
unsigned long long cash[1000][1000];
int mod = 1000000007;

unsigned long long count(int x, int y) {
    
    unsigned long long sum = 1;
    
    if (cash[x][y] > 0) {
        return cash[x][y];
    }
    
    if ((x != 0) && (A[x][y] > A[x-1][y])) {
        sum += count(x-1, y);
    }
    if ((x != W-1) && (A[x][y] > A[x+1][y])) {
        sum += count(x+1, y);
    }
    if ((y != 0) && (A[x][y] > A[x][y-1])) {
        sum += count(x, y-1);
    }
    if ((y != H-1) && (A[x][y] > A[x][y+1])) {
        sum += count(x, y+1);
    }
    sum %= mod;
    cash[x][y] = sum;
    
    return sum;
}

int main()
{
    cin >> H >> W;
    
    for (int y=0; y<H; y++) {
        for (int x=0; x<W; x++) {
            int a;
            scanf("%d", &a);
            A[x][y] = a;
            cash[x][y] = 0;
        }
    }
    
    unsigned long long sum = 0;
    
    for (int x=0; x<W; x++) {
        for (int y=0; y<H; y++) {
            sum += count(x, y);
            sum %= mod;
        }
    }
    
    cout << sum << endl;
    return 0;
}