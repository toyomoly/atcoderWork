#include <iostream>
using namespace std;
int main()
{
    int cnt = 0;
    
    for (int n=0; n<12; n++) {
        string s;
        cin >> s;
        long l = s.length();
        
        bool find = false;
        for (int i=0; i<l; i++) {
            if (s[i] == 'r') {
                find = true;
            }
        }
        if (find) {
            cnt++;
        }
    }
    
    cout << cnt << endl;
    return 0;
}