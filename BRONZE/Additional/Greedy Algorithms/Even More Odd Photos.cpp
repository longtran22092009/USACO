#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


void solve() {
    ll n; cin >> n;

    ll evenCnt = 0, oddCnt = 0;

    for (ll i = 0; i < n; i++) {
        ll num; cin >> num;

        if (num % 2 == 0) evenCnt++;
        else oddCnt++;
    }

    ll ans = 0;

    if (evenCnt == oddCnt) ans = 2 * evenCnt;
    else if (evenCnt > oddCnt) ans = 2 * oddCnt + 1;
    else {
        ll remain = oddCnt - evenCnt;
        ans = 2 * evenCnt + 2 * (remain/3);

        if (remain % 3 == 1) --ans;
        else if (remain % 3 == 2) ++ans;
    }

    cout << ans << endl;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();
}