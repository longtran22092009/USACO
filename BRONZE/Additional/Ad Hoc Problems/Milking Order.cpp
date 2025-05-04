#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "milkorder.in"
#define OUT "milkorder.out"


void solve() {
    ll n, m, k; cin >> n >> m >> k;

    vector <ll> ans(n+1, -1);
    vector <ll> order(m);
    vector <pair <ll, ll>> certain_pos(k);

    map <ll, ll> cow_pos;
    bool oneInOrder = false;

    for (auto &x : order) {
        cin >> x;

        if (x == 1) oneInOrder = true;
    }
    for (ll i = 0; i < k; i++) {
        ll ci, pi; cin >> ci >> pi;

        ans[pi] = ci;
        certain_pos[i] = {ci, pi};
        cow_pos[ci] = pi;

        if (ci == 1) {
            cout << pi;
            return;
        }
    }

    if (oneInOrder) {
        ll curr_pos = 1;

        for (ll i = 0; i < m; i++) {
            ll cow_after = order[i+1];
            ll cow = order[i];

            if (cow_pos.find(cow) != cow_pos.end()) {
                curr_pos = cow_pos[cow]+1;
                continue;
            }

            for (ll i = curr_pos; i <= n; i++) {
                if (ans[i] != -1) continue;

                ans[i] = cow;
                cow_pos[cow] = i;

                curr_pos = i+1;
                break;
            }
        }

        for (ll i = 1; i <= n; i++) {
            if (ans[i] == 1) {
                cout << i;
                return;
            }
        }
    }

    else {
        ll curr_pos = n;

        for (ll i = m-1; i >= 0; i--) {
            ll cow_before = order[i-1];
            ll cow = order[i];

            if (cow_pos.find(cow) != cow_pos.end()) {
                curr_pos = cow_pos[cow]-1;
                continue;
            }

            for (ll i = curr_pos; i >= 1; i--) {
                if (ans[i] != -1) continue;

                ans[i] = cow;
                cow_pos[cow] = i;

                curr_pos = i-1;
                break;
            }
        }

        for (ll i = 1; i <= n; i++) {
            if (ans[i] == -1) {
                cout << i;
                return;
            }
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
