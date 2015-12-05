#include <iostream>
using namespace std;

int solve(int s, int d, int x) {
    
    if (s == d) {
        return x;
    }
    
    if (s % 2 != 0) {
        x++;
        s++;
    }
    
    if (d % 2 != 0) {
        x++;
        d--;
    }
    
    return solve(s/2, d/2, x);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    
    for (int i=0; i<n; i++) {
        int s, d;
        cin >> s >> d;
        a[i] = solve(s, d, 0);
    }
    
    for (int i=0; i<n; i++) {
        cout << a[i] << endl;
    }
    
    return 0;
}