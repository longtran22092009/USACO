#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#define IN "A.in"
#define OUT "A.out"


struct Square {
    ll width, height;
};

ll edge;
bool found = false;
vector <Square> square;
char ans[1000][1000];


void placePiece(ll piece, char board[1000][1000], bool rotate) {
    char ch = '.';
    if (piece == 1) ch = 'A';
    else if (piece == 2) ch = 'B';
    else if (piece == 3) ch = 'C';

    if (piece == 4) {
        for (ll i = 1; i <= edge; i++) {
            for (ll j = 1; j <= edge; j++) {
                if (board[i][j] == '.') return;
            }
        }

        found = true;

        for (ll i = 1; i <= edge; i++) {
            for (ll j = 1; j <= edge; j++) {
                ans[i][j] = board[i][j];
            }
        }

        return;
    }

    ll height = square[piece-1].height;
    ll width = square[piece-1].width;

    if (rotate) {
        height = square[piece-1].width;
        width = square[piece-1].height;
    }

    for (ll i = 1; i <= edge-height+1; i++) {
        for (ll j = 1; j <= edge-width+1; j++) {
            // Check empty space
            bool empty = true;
            for (ll I = i; I <= i+height-1; I++) {
                for (ll J = j; J <= j+width-1; J++) {
                    if (board[I][J] != '.') {
                        empty = false;
                        break;
                    }
                }
            }

            if (!empty) continue;

            // Place the logo into the board
            for (ll I = i; I <= i+height-1; I++) {
                for (ll J = j; J <= j+width-1; J++) {
                    board[I][J] = ch;
                }
            }

            placePiece(piece+1, board, false);

            if (found) return;

            placePiece(piece+1, board, true);
            
            // Backtracking
            for (ll I = i; I <= i+height-1; I++) {
                for (ll J = j; J <= j+width-1; J++) {
                    board[I][J] = '.';
                }
            }
        }
    }
}

void solve() {
    for (ll i = 0; i < 3; i++) {
        ll x, y; cin >> x >> y;
        if (x > y) square.push_back({x, y});
        else square.push_back({y, x});
    }

    ll area = (square[0].width * square[0].height) + (square[1].width * square[1].height) + (square[2].width * square[2].height);
    edge = sqrt(area);
 
    if (edge * edge != area) {
        cout << -1;
        return;
    }

    char board[1000][1000];
    memset(board, '.', sizeof(board));

    placePiece(1, board, false);
    placePiece(1, board, true);
    
    if (!found) {
        cout << -1;
        return;
    }

    cout << edge << endl;

    for (ll i = 1; i <= edge; i++) {
        for (ll j = 1; j <= edge; j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

signed main() {
    if (fopen(IN, "r")) {
        freopen(IN, "r", stdin);
        freopen(OUT, "w", stdout);
    }

    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();
}