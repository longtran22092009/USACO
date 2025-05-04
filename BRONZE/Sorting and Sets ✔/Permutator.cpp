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

    for (ll i = 0; i < n; i++) {
        // (i+1)*(n-1) is the number of subarray that each number is in;
        a[i] *= (i+1)*(n-i);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<ll>());

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ans += a[i] * b[i];
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