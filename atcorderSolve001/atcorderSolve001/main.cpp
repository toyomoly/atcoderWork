#include <iostream>
using namespace std;
int main()
{
    string S;
    int N;
    cin >> S;
    cin >> N;

    int x = (N - 1) / 5;
    int y = (N - 1) % 5;
    
    cout << S[x] << S[y] << endl;
    return 0;
}