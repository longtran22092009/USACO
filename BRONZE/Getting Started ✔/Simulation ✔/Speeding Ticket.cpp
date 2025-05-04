#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    
    int n, m; cin >> n >> m;
    int road[101]{};

    int curr_idx = 1;
    for (int i = 0; i < n; i++) {
        int length, limit; cin >> length >> limit;

        for (int pos = curr_idx; pos < curr_idx + length; pos++) {
            road[pos] = limit;
        }
        curr_idx += length;  
    }
  
    int ans = 0;
    curr_idx = 1;
    for (int i = 0; i < m; i++) {
        int length, speed; cin >> length >> speed;

        for (int pos = curr_idx; pos < curr_idx + length; pos++) {
            ans = max(ans, speed - road[pos]);
        }
        curr_idx += length;  
    }
    cout << ans;
}
