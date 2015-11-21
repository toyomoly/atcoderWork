#include <iostream>
using namespace std;
int main()
{
    int a, d;
    cin >> a >> d;
    cout << ((a < d) ? (++a * d) : (a * ++d)) << endl;
    return 0;
}