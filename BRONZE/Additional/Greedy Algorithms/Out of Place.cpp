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

    vector <ll> order = cow;
    sort(order.begin(), order.end());

    map <ll, ll> change;

    for (ll i = 0; i < n; i++) {
        if (cow[i] != order[i]) change[cow[i]] = i;
    }

    ll cnt = 0;

    for (ll i = 0; i < n; i++) {
        if (cow[i] != order[i]) {
            ++cnt;

            swap(cow[i], cow[change[order[i]]]);
            swap(change[cow[change[order[i]]]], change[cow[i]]);
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