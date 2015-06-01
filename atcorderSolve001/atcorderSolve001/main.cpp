#include <iostream>
using namespace std;
int main()
{
    int A, B, C, K, S, T;
    cin >> A >> B >> C >> K;
    cin >> S >> T;

    if (S+T >= K) {
        A -= C;
        B -= C;
    }
    cout << (A*S+B*T) << endl;
    return 0;
}