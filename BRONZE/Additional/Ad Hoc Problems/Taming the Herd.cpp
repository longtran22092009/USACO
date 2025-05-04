#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "taming.in"
#define OUT "taming.out"


void solve() {
    // ll n; cin >> n;
    // vector <ll> record(n, -1);
    // for (auto &x : record) cin >> x;

    // ll cnt = 0;

    // if (record[0] != -1 && record[0] != 0) {
    //     cout << -1;
    //     return;
    // }

    // for (ll i = 1; i < n; i++) {
    //     if (record[i] == -1) continue;

    //     if (record[i-record[i]] != -1 && record[i-record[i]] != 0) {
    //         cout << -1;
    //         return;
    //     }

    //     record[i-record[i]] = 0;

    //     for (ll j = i-record[i]+1; j < i; j++) record[j] = -2;
    // }

    // for (auto &x : record) {
    //     if (x == 0) ++cnt;
    // }

    // ll minTime = cnt, maxTime = cnt;
    // for (ll i = 1; i < n; i++) {
    //     if (record[i] == -1) ++maxTime;
    // }

    // if (record[0] == -1) {
    //     ++minTime;
    //     ++maxTime;
    // }

    // cout << minTime << " " << maxTime;

    ll n; cin >> n;
    vector <ll> record(n);
    for (auto &x : record) cin >> x;
    
    if (record[0] > 0) {
        cout << -1;
        return;
    }
    record[0] = 0;

    ll lastBreakout = -1;

    for (ll i = n-1; i >= 0; i--) {
        if (record[i] == -1) continue;

        lastBreakout = record[i];

        ll j = i;
        while (lastBreakout >= 0) {
            if (record[j] != -1 && record[j] != lastBreakout) {
                cout << -1;
                return;
            }

            record[j] = lastBreakout;
            --lastBreakout;
            --j;
        }
    }

    ll cnt = 0;
    ll minMove = 0, maxMove = 0;

    for (auto &x : record) {
        if (x == 0) ++cnt;
        else if (x == -1) ++maxMove;
    }

    minMove = cnt;
    maxMove += cnt;

    cout << minMove << " " << maxMove;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();
}