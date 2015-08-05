#include <iostream>
using namespace std;

char get() {
    string P, Q, R;
    cin >> P >> Q >> R;
    int l = (int)R.length();
    
    if (P == "BEGINNING") {
        return R.at(0);
    } else if (P == "END") {
        return R.at(l - 1);
    } else {
        return R.at(l / 2);
    }
}

int main() {
    int N;
    cin >> N;
    
    char s[N];
    for (int i=0; i<N; i++) {
        s[i] = get();
    }

    for (int i=0; i<N; i++) {
        cout << s[i];
    }
    cout << endl;
    return 0;
}

