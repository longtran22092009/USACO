#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "notlast.in"
#define OUT "notlast.out"


void solve() {
    ll n; cin >> n;
    map <string, ll> cow_milk;

    for (ll i = 0; i < n; i++) {
        string cow; cin >> cow;
        ll milk; cin >> milk;

        cow_milk[cow] += milk;
    }

    vector <pair <ll, string>> inf;
    for (auto &x : cow_milk) inf.push_back({x.second, x.first});
    sort(inf.begin(), inf.end());

    ll minMilk = inf[0].first;
    if (inf.size() < 7) minMilk = 0;

    for (ll i = 0; i < inf.size(); i++) {
        if (inf[i].first > minMilk) {
            if (inf[i+1].first != inf[i].first) {
                cout << inf[i].second << endl;
                return;
            }
            else break;
        }
    }

    cout << "Tie" << endl;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();
}