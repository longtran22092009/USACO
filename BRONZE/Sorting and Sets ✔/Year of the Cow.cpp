#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"

void solve() {
    ll n; cin >> n;
    map <string, ll> zodiac 
    = {{"Ox", 1}, {"Tiger", 2}, {"Rabbit", 3}, {"Dragon", 4}, {"Snake", 5}, {"Horse", 6}
    , {"Goat", 7}, {"Monkey", 8}, {"Rooster", 9}, {"Dog", 10}, {"Pig", 11}, {"Rat", 12}};

    map <string, ll> cow_year = {{"Bessie", 1}};
    map <string, ll> diff = {{"Bessie", 1}};

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        string first, year, second, type;
        cin >> first >> second >> second >> type >> year >> second >> second >> second;

        ll curr_year = cow_year[second];
        ll dis = 0;

        if (type == "next") {
            dis = 12 - curr_year + zodiac[year];

            if (zodiac[year] > cow_year[second]) dis -= 12;
            ans += dis;
        }

        else {
            dis = -(curr_year + (12 - zodiac[year]));

            if (zodiac[year] < cow_year[second]) dis += 12;

            ans += dis;
        }

        cow_year[first] = zodiac[year];
        diff[first] = diff[second] + dis;
    }

    cout << abs(diff["Elsie"]-1);
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();
}