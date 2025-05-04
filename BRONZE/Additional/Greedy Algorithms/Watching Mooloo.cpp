#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


void solve() {
    ll n, k; cin >> n >> k;

    vector <ll> days(n);
    for (auto &x : days) cin >> x;

    ll cost = n+k;
    for (ll i = 1; i < n; i++) {
        ll d = days[i]-days[i-1]-1;

        cost += min(d, k);
    }

    cout << cost;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();
}