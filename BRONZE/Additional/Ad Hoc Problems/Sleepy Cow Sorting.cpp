#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "sleepy.in"
#define OUT "sleepy.out"


void solve() {
    ll n; cin >> n;
    
    vector <ll> num(n);
    for (auto &x : num) cin >> x;

    // Solution 1: //

    // ll ans = 0, start = 0;
    // bool unorder = false;
    // for (ll i = 0; i < n; i++) {
    //     if (num[i] == 1) {
    //         start = i;
    //         break;
    //     }
    //     ++ans;
    // }
    // for (ll i = n-1; i >= start; i--) {
    //     if (num[i-1] > num[i]) {
    //         ans += i-start-1;
    //         unorder = true;
    //         break;
    //     }
    // }
    // if (unorder) ++ans;
    // cout << ans;

    // Solution 2: //

	ll ans = n-1;

	for (int i = n-2; i >= 0; i--) {
		if (num[i] < num[i+1]) {
			ans = i;
		} else {
			break;
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

    solve();
}