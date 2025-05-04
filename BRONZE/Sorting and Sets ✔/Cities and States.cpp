#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "citystate.in"
#define OUT "citystate.out"


void solve() {
    ll n; cin >> n;
    multiset <pair <string, string>> code_city;

    for (ll i = 0; i < n; i++) {
        string code, city;
        cin >> city >> code;

        code_city.insert({city.substr(0, 2), code});
    }
    
    ll ans = 0;
    for (auto &inf : code_city) {
        pair <string, string> find_inf = {inf.second, inf.first};

        if (inf.first != inf.second) {
            ll cnt = code_city.count(find_inf);
            ans += cnt;
        }
    }

    cout << ans/2 << endl;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();
}