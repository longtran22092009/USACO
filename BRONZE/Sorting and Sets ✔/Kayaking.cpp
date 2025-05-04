#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "cowqueue.in"
#define OUT "cowqueue.out"

void solve() {
    ll n; cin >> n;
    vector <pair <ll,ll>> cows(n);

    for (ll i = 0; i < n; i++) {
        cin >> cows[i].first >> cows[i].second;
    }
    sort(cows.begin(), cows.end());

    ll time = 0;
    for (auto &cow : cows) {
        ll arrive = cow.first;
        ll answer = cow.second;

        if (arrive < time) {
            time += answer;
        }
        else {
            time = arrive + answer;
        }
    }

    cout << time;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();
}
