#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Cow {
    ll x, y;
};

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);

    ll n, b; cin >> n >> b;
    vector <Cow> cows;
    set <ll> x_coor, y_coor;

    for (int i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        cows.push_back({x, y});
        x_coor.insert(x+1);
        y_coor.insert(y+1);
    }

    ll ans = INT32_MAX;
    for (auto a : x_coor) {
        for (auto b : y_coor) {
            int region[4] = {0, 0, 0, 0};
            for (auto cow : cows) {
                if (cow.x < a && cow.y < b) region[0]++;
                else if (cow.x < a && cow.y > b) region[1]++;
                else if (cow.x > a && cow.y < b) region[2]++;
                else region[3]++;
            }
            ll M = *max_element(region, region+4);
            ans = min(ans, M);
        }
    }

    cout << ans;
}
