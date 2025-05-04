#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


void solve() {
    ll n; cin >> n;

    vector <vector <ll>> board(n, vector <ll>(n));

    for (auto &x : board) {
        for (auto &y : x) cin >> y;
    }

    // for (auto &x : board) {
    //     for (auto &y : x) cout << y;
    //     cout << endl;
    // }

    ll ans = 0;
    for (auto &x : board) {
        ll A = 0, B = 0;

        for (ll i = 0; i < n; i += 2) {
            A += x[i];

            if (i+1 < n) B += x[i+1];
        }

        ans += max(A, B);
    }

    ll sum = 0;
    for (ll j = 0; j < n; j++) {
        ll A = 0, B = 0;
        for (ll i = 0; i < n; i += 2) {
            A += board[i][j];

            if (i+1 < n) B += board[i+1][j];
        }

        sum += max(A, B);
    }

    ans = max(ans, sum);

    cout << ans;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();
}