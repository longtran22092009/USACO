#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n; cin >> n;
    vector <ll> a(n);
    for (auto &x : a) cin >> x;

    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n-1; j++) {
            if (a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
                ++cnt;
            }
        }
    }

    cout << "Array is sorted in " << cnt << " swaps." << endl;
    cout << "First Element: " << a[0] << endl; 
    cout << "Last Element: " << a[n-1] << endl; 
}