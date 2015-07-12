#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int A, B, C;

double ft(double t) {
    return A * t + B * sin(C * t * M_PI);
}

int main()
{
    cin >> A >> B >> C;

    double t = 0;
    double mx = 0;
    
    while (ft(mx) < 100) {
        mx += 1000;
    }
    double mn = mx - 1000;
    
    double r = 0;
    
    while (!((r > 100) && (r - 100 < 0.0000001))) {
        t = (mx + mn) / 2;
        r = ft(t);
        if (r > 100) {
            mx = t;
        } else {
            mn = t;
        }
    }
    
    cout << fixed << setprecision(10) << t;
    return 0;
}