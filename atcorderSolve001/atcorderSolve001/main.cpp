#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> box;

bool comp(const pair<int, int> &lhs,  const pair<int, int> &rhs) {
    return (lhs.first > 0) && (lhs.first < rhs.first);
}

int loop(int i, int nw, int nh, int cnt, int N) {

    if (i == N) {
        return cnt;
    } else {
        if ((nw < box[i].first) && (nh < box[i].second)) {
            // この箱に入れた場合と入れない場合のmax
            return max(loop(i + 1, nw, nh, cnt, N), loop(i + 1, box[i].first, box[i].second, cnt + 1, N));
        } else {
            // この箱には入らない
            return loop(i + 1, nw, nh, cnt, N);
        }
    }
}

int main()
{
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int w, h;
        cin >> w >> h;
        
        box.push_back((make_pair(w, h)));
    }
    
    sort(box.begin(), box.end());
    
    cout << loop(0, 0, 0, 0, N) << endl;
    
    return 0;
}