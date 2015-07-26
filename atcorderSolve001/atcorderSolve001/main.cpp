#include <iostream>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;

    int a[N + M];
    bool c[N];
    for (int i=0; i<N; i++) {
        a[M + i] = i + 1;
        c[i] = false;
    }
    for (int i=0; i<M; i++) {
        cin >> a[M - 1 - i];
    }

    for (int i=0; i<N + M; i++) {
        if (c[a[i] - 1] == false) {
            c[a[i] - 1] = true;
            cout << a[i] << endl;
        }
    }
    
    return 0;
}