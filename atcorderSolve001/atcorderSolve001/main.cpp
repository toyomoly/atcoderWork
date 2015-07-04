#include <iostream>
using namespace std;
int main()
{
    int x, y, k;
    cin >> x >> y >> k;

    cout << ((y > k) ? (x + k) : (x + y - (k - y))) << endl;
    return 0;
}