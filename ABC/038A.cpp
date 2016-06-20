#include <iostream>

using namespace std;

int main()
{
    string S;
    cin >> S;

    cout << ((S[S.length() - 1] == 'T') ? "YES" : "NO") << endl;
    
    return 0;
}