#include <iostream>
using namespace std;

int b11, b12, b13;
int b21, b22, b23;
int c11, c12;
int c21, c22;
int c31, c32;

int scoreAll() {
    return b11 + b12 + b13 + b21 + b22 + b23
         + c11 + c12 + c21 + c22 + c31 + c32;
}

int scoreSub(string S) {
    
    int scoreChokudai = 0;
    
    if (S[0] == S[3]) scoreChokudai += b11;
    if (S[1] == S[4]) scoreChokudai += b12;
    if (S[2] == S[5]) scoreChokudai += b13;
    if (S[3] == S[6]) scoreChokudai += b21;
    if (S[4] == S[7]) scoreChokudai += b22;
    if (S[5] == S[8]) scoreChokudai += b23;
    
    if (S[0] == S[1]) scoreChokudai += c11;
    if (S[1] == S[2]) scoreChokudai += c12;
    if (S[3] == S[4]) scoreChokudai += c21;
    if (S[4] == S[5]) scoreChokudai += c22;
    if (S[6] == S[7]) scoreChokudai += c31;
    if (S[7] == S[8]) scoreChokudai += c32;
    
    return 2 * scoreChokudai - scoreAll();
}

string writeMark(string S, int targetIndex, char mark) {
    int idx = 0;
    for (int i=0; i<9; i++) {
        if (S[i] == '0') {
            if (idx == targetIndex) {
                S[i] = mark;
                return S;
            }
            idx++;
        }
    }
    return S;
}

int loop(int N, string S) {
    
    if (N == 8) {
        // 最後の一個を置く
        S = writeMark(S, 0, 'o');
        // スコアを返す
        return scoreSub(S);
    }
    
    if(N % 2 == 0) {
        // 直大、空いているマスに 'o'
        int max = loop(N + 1, writeMark(S, 0, 'o'));
        // 全パターン試す
        for (int i=1; i<9-N; i++) {
            int t = loop(N + 1, writeMark(S, i, 'o'));
            if (t > max) max = t;
        }
        return max;
    } else {
        // 直子、空いているマスに 'x'
        int min = loop(N + 1, writeMark(S, 0, 'x'));
        // 全パターン試す
        for (int i=1; i<9-N; i++) {
            int t = loop(N + 1, writeMark(S, i, 'x'));
            if (t < min) min = t;
        }
        return min;
    }
}

int main() {
    
    cin >> b11 >> b12 >> b13;
    cin >> b21 >> b22 >> b23;
    cin >> c11 >> c12;
    cin >> c21 >> c22;
    cin >> c31 >> c32;
    
    int a = scoreAll();
    int dif = loop(0, "000000000");
    int scoreChokudai = (a + dif) / 2;
    cout << scoreChokudai << endl;
    cout << a - scoreChokudai << endl;
    
    return 0;
}