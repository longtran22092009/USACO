#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


void solve() {
    ll n; cin >> n;
    string s; cin >> s;

    ll cnt = 0, type = -1;
    for (ll j = 1; j <= n; j += 2) {
        if (s[j-1] == 'G' && s[j] == 'H') {
            if (type == 0) continue;

            type = 0;
            ++cnt;
        }

        else if (s[j-1] == 'H' && s[j] == 'G') {
            if (type == 1) continue;

            type = 1;
            ++cnt;
        }
    }

    cnt -= type;
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