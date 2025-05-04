#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    int n; cin >> n;
    vector <pair <int, int>> cows(n);
    set <int> fence_x, fence_y;

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        cows[i] = {x, y};
        fence_x.insert(x + 1);
        fence_y.insert(y + 1);
    }

    int M = INT32_MAX;
    for (auto a : fence_x) {
        for (auto b : fence_y) {
            int field[4] = {0, 0, 0, 0};
            for (auto cow : cows) {
                int x = cow.first; 
                int y = cow.second;

                if (x < a && y < b) ++field[0];
                else if (x < a && y > b) ++field[1];
                else if (x > a && y < b) ++field[2];
                else if (x > a && y > b) ++field[3];
            }

            M = min(M, *max_element(field, field+4));
        }
    }

    cout << M;
}