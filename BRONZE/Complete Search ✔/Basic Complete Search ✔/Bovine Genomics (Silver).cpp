#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
int s[500][50], p[500][50], met[64];

bool check(int i, int j, int k) {
    bool ok = true;
    
    for (int a = 0; a < n; a++) {
        met[s[a][i]*16 + s[a][j]*4 + s[a][k]] = 1;
    }
    
    for (int a = 0; a < n; a++) {
        if (met[p[a][i]*16 + p[a][j]*4 + p[a][k]]) ok = false;
    }
    
    for (int a = 0; a < n; a++) {
        met[s[a][i]*16 + s[a][j]*4 + s[a][k]] = 0;
    }

    return ok;
}

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);

    cin >> n >> m;

    // Convert char in string to int;
    for (int i = 0; i < n; i++) {
        string c; cin >> c;
        for (int j = 0; j < m; j++) {
            if (c[j] == 'A') s[i][j] = 0;
            if (c[j] == 'C') s[i][j] = 1;
            if (c[j] == 'G') s[i][j] = 2;
            if (c[j] == 'T') s[i][j] = 3;
        }
    }

    // Convert char in string to int;
    for (int i = 0; i < n; i++) {
        string c; cin >> c;
        for (int j = 0; j < m; j++) {
            if (c[j] == 'A') p[i][j] = 0;
            if (c[j] == 'C') p[i][j] = 1;
            if (c[j] == 'G') p[i][j] = 2;
            if (c[j] == 'T') p[i][j] = 3;
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i+1; j < m; j++) {
            for (int k = j+1; k < m; k++) {
                if (check(i, j, k)) ++ans;
            }
        }
    }

    cout << ans;
}
