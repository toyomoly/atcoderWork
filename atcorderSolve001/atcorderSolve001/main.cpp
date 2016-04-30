#include <iostream>
using namespace std;

int f[262144];
int s[262144];

bool chkParent(int k) {
    if (k == 0) {
        return f[k];
    } else {
        return ( f[k] != chkParent((k - 1) / 2) );
    }
}

void update(int l, int r, int k, int st, int ed){
    
    if (r <= st || ed <= l) {
        return;
    }
    if (l <= st && ed <= r) {
        s[k] = (ed - st) - s[k];
        f[k] = !f[k];
        return;
    }
    
    int md = (st + ed) / 2;
    update(l, r, k*2+1, st, md);
    update(l, r, k*2+2, md, ed);
    s[k] = s[k*2+1] + s[k*2+2];
    s[k] = f[k] ? ((ed - st) - s[k]) : s[k];
}

int get(int l, int r, int k, int st, int ed){
    
    if (r <= st || ed <= l) {
        return 0;
    }
    if (l <= st && ed <= r) {
        return chkParent((k - 1) / 2) ? ((ed - st) - s[k]) : s[k];
    }
    
    int md = (st + ed) / 2;
    return get(l, r, k*2+1, st, md) + get(l, r, k*2+2, md, ed);
}

int main()
{
    int n;
    int Q;
    cin >> n >> Q;
    
    for (int i=0; i<Q; i++) {
        int q, l, r;
        cin >> q >> l >> r;
        if (q == 1) {
            update(l, r, 0, 0, 131072);
        } else {
            cout << get(l, r, 0, 0, 131072) << endl;
        }
    }
    
    cout << flush;
    
    return 0;
}