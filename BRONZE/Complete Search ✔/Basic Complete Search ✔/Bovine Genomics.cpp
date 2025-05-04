#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(int i, vector <string> plain, set <char> spotty_gene) {
    for (auto cow : plain) {
        if (spotty_gene.count(cow[i]) == 1) return false;
    }
    return true;
}

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);

    int n, m; cin >> n >> m;
    vector <string> spotty(n);
    vector <string> plain(n);

    for (auto &x : spotty) cin >> x;
    for (auto &x : plain) cin >> x;

    int ans = 0;
    for (int i = 0; i < m; i++) {
        set <char> spotty_gene;
        for (auto cow : spotty) {
            spotty_gene.insert(cow[i]);
        }

        if (check(i, plain, spotty_gene)) ++ans;
    }

    cout << ans;
}
