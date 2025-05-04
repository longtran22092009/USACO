#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"

void solve() {
    ll k, n; cin >> k >> n;

    // Judges
    vector <ll> judges(k);
    for (auto &x : judges) cin >> x;
    
    // Remembered scores
    multiset <ll> scores;
    for (ll i = 0; i < n; i++) {
        ll num; cin >> num;
        scores.insert(num);
    }

    // Prefix sum all judge at turn i
    vector <ll> prefix(k);
    prefix[0] = judges[0];

    for (ll i = 1; i < k; i++) {
        prefix[i] = prefix[i-1] + judges[i];
    }

    // Find all possible initial scores
    // Just need to check only one score at all position
    set <ll> possible_ans;
    for (ll i = 0; i < k; i++) {
        ll score_before = *scores.begin() - prefix[i];

        possible_ans.insert(score_before);
    }

    // Check how many valid scores
    ll ans = 0;
    for (auto &possible : possible_ans) {
        set <ll> possible_score;

        for (ll i = 0; i < k; i++) {
            ll curr_score = possible + prefix[i];

            if (scores.find(curr_score) != scores.end()) {
                possible_score.insert(curr_score);
            }
        }

        if (possible_score.size() == n) ++ans;
    }

    cout << ans;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();
}