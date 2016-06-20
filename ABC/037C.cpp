#include <iostream>
using namespace std;
int main()
{
    int N, K;
    cin >> N >> K;
    
    int x = (N >= 2 * K) ? K : (N - K + 1);
    unsigned long long sum = 0;
    
    for (int i=1; i<x; i++) {
        int a = 0;
        cin >> a;
        sum += a * i;
    }
    for (int i=0; i<(N - 2 * (x-1)); i++) {
        int a = 0;
        cin >> a;
        sum += a * x;
    }
    for (int i=x-1; i>0; i--) {
        int a = 0;
        cin >> a;
        sum += a * i;
    }
    
    cout << sum << endl;
    return 0;
}