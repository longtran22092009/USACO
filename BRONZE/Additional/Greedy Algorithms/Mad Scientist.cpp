#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "breedflip.in"
#define OUT "breedflip.out"


void solve() {
    ll n; cin >> n;
    string a, b; cin >> a >> b;

    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            while (a[i+1] != b[i+1]) ++i;
            ++cnt;
        }
    }

    cout << cnt;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();
}