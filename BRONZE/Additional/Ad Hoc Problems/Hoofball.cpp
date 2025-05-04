#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "hoofball.in"
#define OUT "hoofball.out"


void solve() {
    ll n; cin >> n;

    vector <ll> cow(n);
    for (auto &x : cow) cin >> x;
    sort(cow.begin(), cow.end());

    // 0 is left and 1 is right
    vector <ll> passingSide(n);
    passingSide[0] = 1;
    passingSide[n-1] = 0;

    for (ll i = 1; i < n-1; i++) {
        if (cow[i] - cow[i-1] <= cow[i+1] - cow[i]) passingSide[i] = 0;
        else passingSide[i] = 1;
    }

    ll curr_side = -1, ballNeeded = 0;

    for (ll i = 1; i < n-1; i++) {
        ll new_side = passingSide[i];

        if (curr_side == 0 && new_side == 1) ++ballNeeded;
        if (curr_side == 1 && new_side == 0) {
            if (passingSide[i-2] == 1 && passingSide[i+1] == 0) ++ballNeeded;
        }

        curr_side = new_side;
    }

    cout << ballNeeded+1;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();
}