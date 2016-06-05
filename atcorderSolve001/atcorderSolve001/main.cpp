#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> box(100000);
vector<int> aCnt(100001);
int N;

//bool comp(const pair<int, int> &lhs,  const pair<int, int> &rhs) {
//    return (lhs.first > 0) && (lhs.first < rhs.first);
//}

int loop(int i, int nw, int nh, int cnt) {

    if (i == N) {
        return cnt;
    } else {
        if ((nw < box[i].first) && (nh < box[i].second)) {
            // この箱に入れた場合と入れない場合のmax
            int m1 = loop(i + 1, nw, nh, cnt);
            int m2 = 0;
            if (aCnt[i] > -1) {
                m2 = aCnt[i] + cnt;
            } else {
                m2 = loop(i + 1, box[i].first, box[i].second, cnt + 1);
                aCnt[i] = m2 - cnt;
            }
            return max(m1 , m2);
        } else {
            // この箱には入らない
            return loop(i + 1, nw, nh, cnt);
        }
    }
}

int main()
{
    cin >> N;
    box.resize(N);
    
    for (int i = 0; i < N; i++) {
        int w, h;
        scanf("%d", &w);
        scanf("%d", &h);
        
        box[i] = make_pair(w, h);
        aCnt[i] = -1;
    }
    
    sort(box.begin(), box.end());
    
    cout << loop(0, 0, 0, 0) << endl;
    
    return 0;
}