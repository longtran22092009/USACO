#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "cowtip.in"
#define OUT "cowtip.out"


void solve() {
    ll n; cin >> n;
    
    vector <vector <ll>> board(n, vector <ll>(n));
    
    for (ll i = 0; i < n; i++) {
        ll s; cin >> s;
        
        for (ll j = n-1; j >= 0; j--) {
            board[i][j] = s % 10;
            s /= 10;
        }
    }

    ll cnt = 0;

    for (ll corner = n-1; corner >= 0; corner--) {
        for (ll i = corner; i >= 0; i--) {
            if (board[corner][i] == 1) {
                // Flip the rectangle from upper-left corner to lower-right corner
                for (ll x = 0; x <= corner; x++) {
                    for (ll y = 0; y <= i; y++) {
                        board[x][y] = (board[x][y] == 1)? 0 : 1;
                    }
                }

                ++cnt;
            }
        }

        for (ll i = corner; i >= 0; i--) {
            if (board[i][corner] == 1) {
                // Flip the rectangle from upper-left corner to lower-right corner
                for (ll x = 0; x <= i; x++) {
                    for (ll y = 0; y <= corner; y++) {
                        board[x][y] = (board[x][y] == 1)? 0 : 1;
                    }
                }

                ++cnt;
            }
        }

        // for (auto &x : board) {
        //     for (auto &y : x) cout << y;
        //     cout << endl;
        // }
        // cout << endl;
    }

    cout << cnt;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();
}