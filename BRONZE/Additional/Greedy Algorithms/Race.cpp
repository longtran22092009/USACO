#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "race.in"
#define OUT "race.out"


ll maxTime(ll &k, ll &x) {
    ll speed_up_dis = 0;
    ll slow_down_dis = 0;
    ll time = 0;

    for (ll curr_speed = 1;; curr_speed++) {
        speed_up_dis += curr_speed;
        ++time;

        if (speed_up_dis + slow_down_dis >= k) return time;

        if (curr_speed >= x) {
            slow_down_dis += curr_speed;
            ++time;
            
            if (speed_up_dis + slow_down_dis >= k) return time;
        }
    }
}

void solve() {
    ll k, n; cin >> k >> n;

    vector <ll> limit(n);
    for (auto &x : limit) cin >> x;

    for (auto &x : limit) {
        cout << maxTime(k, x) << endl;
    }
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();
}