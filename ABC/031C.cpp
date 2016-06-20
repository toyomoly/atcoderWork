#include <iostream>
#include <algorithm>
using namespace std;

int scoreT = 0;
int scoreA = 0;

// 2つのidxが選ばれた時の2人の得点を計算する
void calc(int a[], int idxT, int idxA) {
    int i1, i2;
    if (idxT < idxA) {
        i1 = idxT;
        i2 = idxA;
    } else {
        i1 = idxA;
        i2 = idxT;
    }
    
    int sT = 0, sA = 0;
    for (int i=i1; i<=i2; i++) {
        if ((i - i1) % 2 == 0) {
            sT += a[i];
        } else {
            sA += a[i];
        }
    }
    
    scoreT = sT;
    scoreA = sA;
}

// idxTが選ばれた時に青木くんはどれを選ぶか？その時の高橋くんのスコアを返す
int getScoreT(int n, int a[], int idxT) {
    // 青木くんの選び方を全て試す
    int maxT = -3000, maxA = -3000;
    for (int i=0; i<n; i++) {
        if (i != idxT) {
            calc(a, idxT, i);
            if (maxA < scoreA) {
                maxA = scoreA;
                maxT = scoreT;
            }
        }
    }
    
    // 青木くんのスコアがmaxになる時の高橋くんのスコア
    return maxT;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    
    int maxT = -3000;
    // 高橋くんの選び方を全て試す
    for (int i=0; i<n; i++) {
        maxT = max(maxT, getScoreT(n, a, i));
    }
    
    cout << maxT << endl;
    
    return 0;
}