#include <iostream>
#include <string>
using namespace std;
int main()
{
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << ((b / a) > (d / c) ? "TAKAHASHI" :
        (b / a) < (d / c) ? "AOKI" : "DRAW") << endl;
    return 0;
}