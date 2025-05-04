#include <bits/stdc++.h>
using namespace std;
#define ll long long

int X[100], cnt = 0;
char board[8][8];
bool cot[100], d1[100], d2[100];

void solve(int i) {
    for (int j = 0; j < 8; j++) {
        if (board[i][j] != '*' && cot[j] == 0 && d1[i+j-1] == 0 && d2[i-j+8] == 0) {
            cot[j] = 1;
            d1[i+j-1] = 1;
            d2[i-j+8] = 1;
            X[i] = j;

            if (i == 7) {
                cnt++;
            }
            else {
                solve(i+1);
            }

            cot[j] = 0;
            d1[i+j-1] = 0;
            d2[i-j+8] = 0;
            X[i] = 0;
        }
    }
}

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    
    memset(X, 0, sizeof(X));
    memset(cot, 0, sizeof(cot));
    memset(d1, 0, sizeof(d1));
    memset(d2, 0, sizeof(d2));

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> board[i][j];
        }
    }

    solve(0);
    cout << cnt;
}
