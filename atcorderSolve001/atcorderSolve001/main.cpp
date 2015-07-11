#include <iostream>
using namespace std;

// 未計算の部下をチェック
int checkBuka(int N, int a[], int k[], int x) {
    int c = 0;
    for (int i=1; i<N; i++) {
        if ((a[i] - 1 == x) && (k[i] == 0)) {
            c++;
        }
    }
    return c;
}

// 給与計算
int calc(int N, int a[], int k[], int x) {
    int ma = 1;
    int mi = 0;
    int r = 1;
    for (int i=1; i<N; i++) {
        if (a[i] - 1 == x) {
            ma = max(ma, k[i]);
            mi = (mi == 0) ? k[i] : min(mi, k[i]);
            r = ma + mi + 1;
        }
    }
    return r;
}

int main()
{
    int N;
    cin >> N;

    int a[N], k[N];
    a[0] = 0;
    k[0] = 0;
    for (int i=1; i<N; i++) {
        cin >> a[i];
        k[i] = 0;
    }

    while (k[0] == 0) {
        for (int i=0; i<N; i++) {
            // 社員iを上司にする社員
            if ((k[i] == 0) && (checkBuka(N, a, k, i) == 0)) {
                k[i] = calc(N, a, k, i);
            }
        }
    }
    
    cout << k[0] << endl;
    
    return 0;
}