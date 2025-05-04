#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "angry.in"
#define OUT "angry.out"

void solve() {
    ll n; cin >> n;
    vector <ll> hay(n);
    
    for (auto &x : hay) cin >> x;
    sort(hay.begin(), hay.end());

    ll ans = 0;
    for (ll pos = 0; pos < n; pos++) {
        ll curr = pos;
        ll radius = 1, cnt = 1;

        for (ll i = pos+1; i < n; i++) {
            if (hay[curr] + radius >= hay[i]) {
                ++cnt;
            }
            else {
                if (curr == i-1) break;

                curr = i-1;
                ++radius;
                --i;
            }
        }

        curr = pos;
        radius = 1;
        for (ll i = pos-1; i >= 0; i--) {
            if (hay[curr] - radius <= hay[i]) {
                ++cnt;
            }
            else {
                if (curr == i+1) break;

                curr = i+1;
                ++radius;
                ++i;
            }
        }

        ans = max(ans, cnt); 
    }

    cout << ans << endl;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();
}