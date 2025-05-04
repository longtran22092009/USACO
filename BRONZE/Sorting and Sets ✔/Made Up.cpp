#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


void solve() {
    ll n; cin >> n;

    vector <ll> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    
    map <ll, ll> new_b;
    for (ll i = 0; i < n; i++) {
        ll ci; cin >>  ci;

        new_b[b[ci-1]]++;
    }

    ll ans = 0;
    for (auto &x : a) {
        ans += new_b[x];
    }

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
