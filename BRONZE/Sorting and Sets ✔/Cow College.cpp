#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"

void solve() {
    ll n; cin >> n;
    vector <ll> cow(n);

    for (auto &x : cow) cin >> x;
    sort(cow.begin(), cow.end());

    ll ans = 0, fee = 0;
    for (ll i = 0; i < n; i++) {
        ll sum = cow[i] * (n-i);
        
        if (sum > ans) {
            ans = sum;
            fee = cow[i];
        }
    }

    cout << ans << " " << fee;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();
}