#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    
    int n; cin >> n;
    vector <pair <char, int>> information(n);
    for (auto &x : information) cin >> x.first >> x.second;

    // Assume that for each cow is telling the truth;
    int ans = INT32_MAX;
    for (int i = 0; i < n; i++) {
        int range = information[i].second;

        int liars = 0;
        for (int j = 0; j < n; j++) {
            if (information[j].first == 'G' && information[j].second > range) ++liars;
            if (information[j].first == 'L' && information[j].second < range) ++liars;
        }
        ans = min(ans, liars);
    }

    cout << ans;
}
