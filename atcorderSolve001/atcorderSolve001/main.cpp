#include <iostream>

using namespace std;

int H, W;
int a[10000];

// 周囲に0のマスがなければ収縮前の黒
void check(int i, int j) {
    bool b = true;
    if (i > 0) {
        if (j > 0) {
            if (a[H*(i-1) + (j-1)] == 0) { b = false; }
        }
        
        if (a[H*(i-1) + (j)] == 0) { b = false; }
        
        if (j < (W-1)) {
            if (a[H*(i-1) + (j+1)] == 0) { b = false; }
        }
    }

    if (j > 0) {
        if (a[H*(i) + (j-1)] == 0) { b = false; }
    }
    
    if (a[H*(i) + (j)] == 0) { b = false; }
    
    if (j < (W-1)) {
        if (a[H*(i) + (j+1)] == 0) { b = false; }
    }

    if (i < (H-1)) {
        if (j > 0) {
            if (a[H*(i+1) + (j-1)] == 0) { b = false; }
        }
        
        if (a[H*(i+1) + (j)] == 0) { b = false; }
        
        if (j < (W-1)) {
            if (a[H*(i+1) + (j+1)] == 0) { b = false; }
        }
    }
    
    if (b) {
        a[H*i + j] += 1;
    }
}

// 周囲に1以上のマスがない？
bool check2(int i, int j) {
    bool b = true;
    if (i > 0) {
        if (j > 0) {
            if (a[H*(i-1) + (j-1)] > 1) { b = false; }
        }
        
        if (a[H*(i-1) + (j)] > 1) { b = false; }
        
        if (j < (W-1)) {
            if (a[H*(i-1) + (j+1)] > 1) { b = false; }
        }
    }
    
    if (j > 0) {
        if (a[H*(i) + (j-1)] > 1) { b = false; }
    }
    
    if (a[H*(i) + (j)] > 1) { b = false; }
    
    if (j < (W-1)) {
        if (a[H*(i) + (j+1)] > 1) { b = false; }
    }
    
    if (i < (H-1)) {
        if (j > 0) {
            if (a[H*(i+1) + (j-1)] > 1) { b = false; }
        }
        
        if (a[H*(i+1) + (j)] > 1) { b = false; }
        
        if (j < (W-1)) {
            if (a[H*(i+1) + (j+1)] > 1) { b = false; }
        }
    }
    
    return b;
}

int main()
{

    cin >> H >> W;

    for (int i=0; i<H; i++) {
        string s;
        cin >> s;
        
        for (int j=0; j<W; j++) {
            a[H*i + j] = ((s[j]=='#') ? 1 : 0);
        }
    }
    
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            check(i, j);
        }
    }
    
    bool possible = true;
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            if (a[H*i + j] == 1) {
                if(check2(i, j)) {
                    possible = false;
                }
            }
            
        }
    }
    
    if (possible) {
        cout << "possible" << endl;
        for (int i=0; i<H; i++) {
            for (int j=0; j<W; j++) {
                cout << ((a[H*i + j] > 1) ? '#' : '.');
            }
            cout << endl;
        }
    } else {
        cout << "impossible" << endl;
    }
    
    return 0;
}