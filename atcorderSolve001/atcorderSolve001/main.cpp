#include <iostream>
using namespace std;
int main()
{
    int N, A, B, E=0, W=0;
    cin >> N >> A >> B;

    for (int i=0; i<N; i++) {
        string s;
        cin >> s;
        
        int d;
        cin >> d;
        
        if (d < A) d = A;
        else if (d > B) d = B;

        if (s == "East") E += d;
        else W += d;
    }
    
    if (E > W) {
        cout << "East " << E - W << endl;
    } else if (W > E) {
        cout << "West " << W - E << endl;
    } else {
        cout << "0" << endl;
    }
    
    return 0;
}