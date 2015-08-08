#include <iostream>
#include <math.h>
#include <iomanip>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    cin >> N;

    int a[N];
    for (int i=0; i<N; i++) {
        cin >> a[i];
    }
    // 配列のソート
    sort(a, a+N, greater<int>());

    int r2 = 0;
    for (int i=0; i<N; i++) {
        r2 += a[i] * a[i] * ((i%2 == 1) ? -1 : 1);
    }
    
    cout << fixed << setprecision(10) << (double)r2 * M_PI << endl;
    
    return 0;
}