#include <iostream>
using namespace std;

int main() {
    int N, V = 0, I = 0;
    cin >> N;
    
    for (int i=0; i<N; i++) {
        int A;
        cin >> A;
        if (V < A) {
            V = A;
            I = i;
        }
    }
    cout << I + 1 << endl;
    return 0;
}