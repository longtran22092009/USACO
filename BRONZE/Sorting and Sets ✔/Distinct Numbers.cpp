#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"

/*
Calculate according to the columns
Sort all numbers in non-increasing order
Algorithm:
    a[i] * i - sum
*sum = all element before a[i]*
*/ 

void solve() {
    ll n, m; cin >> n >> m;

    vector <vector <ll>> cards(m);

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            ll num; cin >> num;

            cards[j].push_back(num);
        }
    }

    ll ans = 0;
    for (ll i = 0; i < m; i++) {
        vector <ll> v = cards[i];
        sort(v.begin(), v.end());

        ll sum = 0;
        for (ll j = 0; j < n; j++) {
            ll curr_res = v[j]*j - sum;
            sum += v[j];

            ans += curr_res;
        }
    }

    cout << ans << endl;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);

    ll t; cin >> t;
    while (t--) {
        solve();
    }
}