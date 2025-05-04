#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"

void solve() {
    // Using map: //

    ll n, target; cin >> n >> target;

    vector <ll> nums(n);
    for (ll i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    map <ll, ll> val;
    for (ll i = 0; i < n; i++) {
        ll need = target - nums[i];

        if (val.find(need) != val.end()) {
            cout << i+1 << " " << val[need];
            return;
        }

        val[nums[i]] = i+1;
    }

    cout << "IMPOSSIBLE";

    // Using two pointer method: //

    ll n, target; cin >> n >> target;

    vector <pair <ll, ll>> num(n);
    for (ll i = 1; i <= n; i++) {
        ll val; cin >> val;

        num[i-1] = {val, i};
    }
    sort(num.begin(), num.end());

    ll l = 0, r = n-1;
    while (l < r) {
        ll sum = num[l].first + num[r].first;

        if (sum == target) {
            cout << num[l].second << " " << num[r].second;
            return;
        }
        else if (sum > target) --r;
        else ++l;
    }

    cout << "IMPOSSIBLE";
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();
}