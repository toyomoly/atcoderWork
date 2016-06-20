#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int d = (a < b) ? a : b;
    cout << (c / d) << endl;
    return 0;
}