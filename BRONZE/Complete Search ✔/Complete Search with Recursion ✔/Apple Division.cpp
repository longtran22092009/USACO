#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;

ll calculate(ll i, vector <ll> apple, ll sum1, ll sum2) {
    if (i == n) return abs(sum1 - sum2);

    ll case1 = calculate(i+1, apple, sum1 + apple[i], sum2);
    ll case2 = calculate(i+1, apple, sum1, sum2 + apple[i]);

    return min(case1, case2);
}

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);

    cin >> n;
    vector <ll> apple(n);
    for (int i = 0; i < n; i++) cin >> apple[i];

    ll ans = calculate(0, apple, 0, 0);
    cout << ans;
}
