#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);

    int n; cin >> n;
    vector <pair <int, int>> shift_time(n);

    int limit = 0;
    for (auto &x : shift_time) {
        cin >> x.first >> x.second;
        limit = max(limit, x.second);
    }

    int maxTime = 0;
    for (int fired = 0; fired < n; fired++) {
        int totalTime = 0;
        for (int t = 1; t <= limit; t++) {
            for (int i = 0; i < n; i++) {
                if (i != fired) {
                    if (shift_time[i].first <= t && t < shift_time[i].second) {
                        ++totalTime;
                        break;
                    }
                }
            }
        }
        maxTime = max(maxTime, totalTime);
    }

    cout << maxTime;
}
