#include <iostream>
using namespace std;
int main()
{
    int N, Q;
    cin >> N >> Q;
    
    int A[N];
    
    for (int i=0; i<N; i++) {
        A[i] = 0;
    }
    
    for (int i=0; i<Q; i++) {
        int L, R, T;
        cin >> L >> R >> T;
        
        for (int j=(L-1); j<R; j++) {
            A[j] = T;
        }
    }

    for (int i=0; i<N; i++) {
        cout << A[i] << endl;
    }
    return 0;
}