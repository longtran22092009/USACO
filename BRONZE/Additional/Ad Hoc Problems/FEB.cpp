#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


void solve() {
    ll n; cin >> n;
    string s; cin >> s;

    vector <pair <ll, ll>> segmentF;

    for (ll i = 0; i < n; i++) {
        ll start = 0, end = 0;

        if (s[i] == 'F') {
            start = i;
            while (s[i+1] == 'F') ++i;
            end = i;

            segmentF.push_back({start, end});
        }
    }
    
    ll bigSize = 1;
    vector <vector <ll>> ans;

    for (auto &x : segmentF) {
        ll start = x.first, end = x.second;
        ll d = end-start+1;

        vector <ll> values;

        if (d == n) {
            for (ll i = d-1; i >= 0; i -= 1) {
                values.push_back(i);
            }
        }

        else if (start == 0 || end == n-1) {
            for (ll i = d; i >= 0; i -= 1) {
                values.push_back(i);
            }
        }
        
        else {
            if (s[start-1] == s[end+1]) {
                for (ll i = d+1; i >= 0; i -= 2) {
                    values.push_back(i);
                }
            }
            else {
                for (ll i = d; i >= 0; i -= 2) {
                    values.push_back(i);
                }
            }
        }

        ans.push_back(values);
        bigSize *= values.size();
    }

    ll default_val = 0;

    for (ll i = 0; i < n; i++) {
        if (s[i] == 'B') {
            ll cnt = 1;
            while (s[i+1] == 'B') {
                ++cnt;
                ++i;
            }

            default_val += cnt-1;
        }
        
        if (s[i] == 'E') {
            ll cnt = 1;
            while (s[i+1] == 'E') {
                ++cnt;
                ++i;
            }

            default_val += cnt-1;
        }
    }

    unordered_set <ll> distinct_val(ans[0].begin(), ans[0].end());

    for (ll i = 1; i < ans.size(); i++) {
        unordered_set <ll> new_val;

        for (auto &x : distinct_val) {
            for (auto &y : ans[i]) {
                new_val.insert(x+y);
            }
        }

        distinct_val = new_val;
    }

    cout << distinct_val.size() << endl;
    for (auto &x : distinct_val) cout << x + default_val << endl;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();
}
