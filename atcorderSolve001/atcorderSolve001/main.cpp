#include <iostream>
using namespace std;
int main()
{
    int N, R;
    cin >> N >> R;
    
    string S;
    cin >> S;

    int T = 0;
    
    
    // idx(N-1)から見て行く
    // oならOK
    if (S[N-1] == 'o') {
        
    } else {
        if (N-1<=R) {
            // 発射で終わり
            T++;
        }else{
            // 進む必要がある
        }
    }
    
    
    // idx(N-2)を見る
    
    
    cout << T << endl;
    return 0;
}