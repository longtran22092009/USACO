#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "art.in"
#define OUT "art.out"


struct Shape {
    ll minx = LONG_LONG_MAX, miny = LONG_LONG_MAX;
    ll maxx = 1, maxy = 1;
};

ll n;

bool check(vector <vector <ll>> original_canvas, vector <vector <ll>> check_canvas, ll first_color) {
    for (ll i = 1; i <= n; i++) {
        for (ll j = 0; j <= n; j++) {
            if (original_canvas[i][j] == first_color && check_canvas[i][j] != first_color) return false;
        }
    }

    return true;
}

void solve() {
    cin >> n;
    vector <vector <ll>> canvas(n+1, vector <ll> (n+1));
    set <ll> colors;

    // Parse the input and save no of color still can be seen
    for (ll i = 1; i <= n; i++) {
        ll row; cin >> row;

        for (ll j = n; j >= 1; j--) {
            if (row%10 != 0) colors.insert(row % 10);

            canvas[i][j] = row % 10;
            row /= 10;
        }
    }

    // Get the rectangle shape of each color
    map <ll, Shape> shapes;

    for (auto &color : colors) {
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                if (canvas[i][j] == color && canvas[i][j] != 0) {
                    shapes[color].minx = min(shapes[color].minx, i);
                    shapes[color].miny = min(shapes[color].miny, j);
                    shapes[color].maxx = max(shapes[color].maxx, i);
                    shapes[color].maxy = max(shapes[color].maxy, j);
                }
            }
        }
    }

    // for (auto &shape : shapes) {
    //     cout << "Color: " << shape.first << endl;
    //     cout << "Start: " << shape.second.minx;
    //     cout << ", End: " << shape.second.maxx << endl;
    //     cout << "Start: " << shape.second.miny;
    //     cout << ", End: " << shape.second.maxy << endl;
    //     cout << endl;
    // }
    
    // Check if each color can be painted first
    ll ans = 0;

    for (auto &color : colors) {
        vector <vector <ll>> new_canvas(n+1, vector <ll> (n+1, 0));

        for (ll i = shapes[color].minx; i <= shapes[color].maxx; i++) {
            for (ll j = shapes[color].miny; j <= shapes[color].maxy; j++) {
                new_canvas[i][j] = color;
            }
        }

        for (auto &color_after : colors) {
            if (color_after == color) continue;

            for (ll i = shapes[color_after].minx; i <= shapes[color_after].maxx; i++) {
                for (ll j = shapes[color_after].miny; j <= shapes[color_after].maxy; j++) {
                    new_canvas[i][j] = color_after;
                }
            }
        }

        // cout << "Color: " << color << endl;
        // for (ll i = 1; i <= n; i++) {
        //     for (ll j = 1; j <= n; j++) {
        //         cout << new_canvas[i][j];
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        if (check(canvas, new_canvas, color)) ++ans;
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
