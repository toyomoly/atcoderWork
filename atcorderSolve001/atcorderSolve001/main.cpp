#include <iostream>
#include <queue>
using namespace std;
int main()
{
    // 1~nまでの数をq個の数字で割った時に残る1の数
    long n;
    int q;
    cin >> n >> q;
    long a[q];
    
    for (int i=0; i<q; i++) {
        cin >> a[i];
    }
    
    queue<pair<long, int>> qu;
    qu.push(pair<long, int>(1, q));
    
    for (int i=q-1; i>=0; i--) {
        
        queue<pair<long, int>> newqu;
        
        while (qu.size() > 0) {
            pair<long, int> p = qu.front();
            
            if (a[i] * p.first <= n) {
                newqu.push(pair<long, int>(a[i] * p.first, i));
            }
            if ((p.first % a[i]) != 0) {
                newqu.push(pair<long, int>(p.first, i));
            }
            
            qu.pop();
        }
        
        qu = newqu;
    }
    
    cout << qu.size() << endl;
    
    return 0;
}