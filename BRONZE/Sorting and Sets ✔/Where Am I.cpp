#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"

void solve() {
    ll n; cin >> n;
    string s; cin >> s;

    for (ll i = 1; i <= n; i++) {
        set <string> pattern;

        for (ll j = 0; j <= n-i; j++) {
            string sub = s.substr(j, i);
            pattern.insert(sub);
        }

        if (pattern.size() >= n-i+1) {
            cout << i;
            return; 
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