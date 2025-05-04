#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    
    int m, n, k;
    cin >> m >> n >> k;
    char signal[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> signal[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int line = 0; line < k; line++) {
            for (int j = 0; j < n; j++) {
                for (int loop = 0; loop < k; loop++) 
                    cout << signal[i][j];
            }
            cout << endl;
        }
    }
}