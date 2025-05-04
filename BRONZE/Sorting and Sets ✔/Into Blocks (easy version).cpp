#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


void solve() {
    ll n, q; cin >> n >> q;
    vector <ll> a(n);
    for (auto &x : a) cin >> x;

    // All position of a number <=> frequency of number
    map <ll, vector<ll>> num_segment;
    for (ll i = 0; i < n; i++) {
        num_segment[a[i]].push_back(i);
    }

    // All segment of each number
    vector <pair <pair <ll, ll>, ll>> segment;
    for (auto &x : num_segment) {
        pair <ll, ll> start_end = {*(x.second.begin()), *(x.second.rbegin())};

        segment.push_back({start_end, x.first});
    }

    // Sort in ascending order
    sort(segment.begin(), segment.end());

    // Merge all segment into some blocks
    ll curr_start = 0, curr_end = 0;
    vector <ll> appear_num;
    vector <pair <pair <ll, ll>, vector <ll>>> ans;
    
    for (ll i = 0; i < segment.size(); i++) {
        ll start = segment[i].first.first;
        ll end = segment[i].first.second;
        ll num = segment[i].second;

        if (start < curr_end) {
            if (end > curr_end) {
                curr_end = end;
            }
        }

        else {
            ans.push_back({{curr_start, curr_end}, appear_num});
            appear_num.clear();

            curr_start = start;
            curr_end = end;
        }

        appear_num.push_back(num);
    }
    ans.push_back({{curr_start, curr_end}, appear_num});
    ans.erase(ans.begin());

    // Calculate the minimum of position should be change to make blocks
    ll sum = 0;
    for (auto &x : ans) {
        ll minChange = 0;
        for (auto &y : x.second) {
            ll freq = num_segment[y].size();
            minChange = max(minChange, freq);
        }
        
        ll length = x.first.second - x.first.first + 1;
        minChange = length - minChange;

        sum += minChange;
    }

    cout << sum << endl;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();
}
