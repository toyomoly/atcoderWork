#include <iostream>
using namespace std;

int main() {
    long N;
    cin >> N;
    
    if (N % 4 == 0) {
        cout << "GO" << endl;
    } else {
        cout << "SEN" << endl;
    }
    return 0;
}
