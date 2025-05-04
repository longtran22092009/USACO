#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);

    int n; cin >> n;
    vector <int> x(n);
    vector <int> y(n);
    
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int z = 0; z < n; z++) {
                if (y[i] == y[j] && x[i] == x[z]) {
                    int area = abs((x[j] - x[i]) * (y[z] - y[i]));
                    ans = max(ans, area);
                }
            }
        }
    }

    cout << ans;
}
