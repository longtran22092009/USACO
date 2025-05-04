#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "herding.in"
#define OUT "herding.out"


void solve() {
    vector <ll> pos(3);
    for (auto &x : pos) cin >> x;
    sort(pos.begin(), pos.end());

    ll dis1 = pos[1] - pos[0] - 1;
    ll dis2 = pos[2] - pos[1] - 1;

    ll minDis = 0;
    ll maxDis = max(dis1, dis2);

    if (dis1 == 0 && dis2 == 0) minDis = 0;
    else if (dis1 == 1 || dis2 == 1) minDis = 1;
    else minDis = 2;

    cout << minDis << endl << maxDis;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();
}