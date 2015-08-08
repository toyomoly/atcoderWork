#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    int N, M, S;
    cin >> N >> M >> S;

    vector<pair<int, int>> pairs(N);
    for (int i=0; i<N; i++) {
        int T, K;
        cin >> T >> K;
        pairs[i] = make_pair(T, K);
    }
    sort(pairs.begin(), pairs.end());

    int t = 0, k = 0, tmp = 0;
    for (int i=0; i<N; i++) {
        if (k >= M) {
            t += pairs[i].first - tmp;
        }
        tmp = pairs[i].first;
        k += pairs[i].second;
    }
    if (k >= M) {
        t += S - tmp;
    }
    
    cout << t << endl;
    return 0;
}