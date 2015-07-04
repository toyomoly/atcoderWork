#include <iostream>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;

    int a[N][M];
    int b[N][M];
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            a[i][j] = 0;
            char c;
            cin >> c;
            b[i][j] = (int)(c - '0');
        }
    }
    for (int i=0; i<N-1; i++) {
        for (int j=0; j<M-1; j++) {
            if (b[i][j] > 0) {
                if (j == 0) {
                    cout << "okasii" << endl;
                } else {
                    a[i+1][j] = b[i][j];
                    b[i+1][j-1] -= b[i][j];
                    b[i+1][j+1] -= b[i][j];
                    b[i+2][j] -= b[i][j];
                }
            }
        }
    }
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}