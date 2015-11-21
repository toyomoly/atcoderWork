#include <iostream>
using namespace std;
int main()
{
    int l, h, n;
    cin >> l >> h >> n;
    
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        cout << ((a < l) ? (l - a) :
            (a > h) ? -1 : 0) << endl;
    }
    return 0;
}