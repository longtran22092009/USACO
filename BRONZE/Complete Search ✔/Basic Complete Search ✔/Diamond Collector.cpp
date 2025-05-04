#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    
    int n, k; cin >> n >> k;
    vector <int> diamondSize(n);

    for (auto &x : diamondSize) cin >> x;  
    sort(diamondSize.begin(), diamondSize.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        for (int j = i+1; j < n; j++) {
            if (abs(diamondSize[i] - diamondSize[j]) <= k) 
                ++cnt;
        }
        ans = max(ans, cnt);
    }

    cout << ans;
}
