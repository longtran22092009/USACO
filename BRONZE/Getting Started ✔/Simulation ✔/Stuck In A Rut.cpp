#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll INF = 1e9 + 7;

struct Cow {
    ll x, y, idx;
};

bool northComp(Cow a, Cow b) {
    return a.x < b.x;
}

bool eastComp(Cow a, Cow b) {
    return a.y < b.y;
}

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    
    ll n; cin >> n;
    vector <Cow> north_cow;
    vector <Cow> east_cow;

    // Parse the input;
    for (ll i = 0; i < n; i++) {
        char dir; ll x, y;
        cin >> dir >> x >> y;

        if (dir == 'E') {
            east_cow.push_back({x, y, i});
        }
        else {
            north_cow.push_back({x, y, i});
        }
    }
    // Sort to ensure that the earliest collision will occurr first;
    sort(north_cow.begin(), north_cow.end(), northComp);
    sort(east_cow.begin(), east_cow.end(), eastComp);

    // Check for collisions between each two cow;
    vector <ll> dis(n, -1);
    for (auto cow_north : north_cow) {
        for (auto cow_east : east_cow) {
            if (cow_north.x > cow_east.x && cow_north.y < cow_east.y) {
                ll north_dis = cow_east.y - cow_north.y;
                ll east_dis = cow_north.x - cow_east.x;

                if (north_dis < east_dis && dis[cow_east.idx] == -1) {
                    dis[cow_east.idx] = east_dis;
                } 
                if (north_dis > east_dis && dis[cow_east.idx] == -1) {
                    dis[cow_north.idx] = north_dis;
                    break;
                }
            }
        }
    }

    for (auto grass : dis) cout << (grass == -1 ? "Infinity" : to_string(grass)) << endl;
}
