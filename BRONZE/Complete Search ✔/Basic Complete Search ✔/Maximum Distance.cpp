#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    
    int n; cin >> n;

    vector <int> x_coor(n);
    vector <int> y_coor(n);

    for (int i = 0; i < n; i++) cin >> x_coor[i];
    for (int i = 0; i < n; i++) cin >> y_coor[i];
    
    ll max_dis = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll dx = x_coor[i] - x_coor[j];
            ll dy = y_coor[i] - y_coor[j];

            max_dis = max(max_dis, dx*dx + dy*dy);
        }
    }

    cout << max_dis;
}
