#include <iostream>
using namespace std;
int main()
{
    string S;
    cin >> S;
    int n = 0;
    char last = 'O';
    long l = S.length();
    for (int i=0; i<l; i++) {
        if (S[i] != last) {
            last = S[i];
            n++;
        }
    }
    int res = ((last == 'O') ? (n - 1) : n);
    
    cout << ((res < 0) ? 0 : res) << endl;
    return 0;
}