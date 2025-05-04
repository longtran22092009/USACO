#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"

void solve() {
    ll Q; cin >> Q;

    map <ll, ll> val;
    while (Q--) {
        ll op, k, v;
        cin >> op;

        if (op == 0) {
            cin >> k >> v;

            val[k] = v;
        }
        else {
            cin >> k;

            cout << val[k] << endl;
        }
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