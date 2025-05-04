#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    
    int n; cin >> n;
    vector <int> petals(n);
    for (auto &x : petals) cin >> x;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int cnt = accumulate(petals.begin()+i, petals.begin()+j+1, 0);

            if (cnt % (j-i+1) == 0) cnt /= (j-i+1);
            for (int idx = i; idx <= j; idx++) {
                if (petals[idx] == cnt) {
                    ++ans;
                    break;
                }
            }
        }
    }

    cout << ans;
}
