#include <iostream>
using namespace std;
int main()
{
    int N, R=0, B=0;
    cin >> N;

    for (int i=0; i<N; i++) {
        string s;
        cin >> s;
        
        for (int j=0; j<N; j++) {
            if (s[j] == 'R') R++;
            else if (s[j] == 'B') B++;
        }
    }
    
    cout << ((R > B) ? "TAKAHASHI" : (R < B) ? "AOKI" : "DRAW") << endl;
    return 0;
}