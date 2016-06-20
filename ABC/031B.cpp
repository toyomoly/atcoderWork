#include <iostream>
using namespace std;
int main()
{
    int l, h, n;
    cin >> l >> h >> n;
    int a[n];
    
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    
    for (int i=0; i<n; i++) {
        cout << ((a[i] < l) ? (l - a[i]) :
            (a[i] > h) ? -1 : 0) << endl;
    }
    return 0;
}