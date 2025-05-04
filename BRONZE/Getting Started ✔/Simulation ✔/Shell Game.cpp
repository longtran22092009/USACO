#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    
    int n; cin >> n;
    int case1 = 0, case2 = 0, case3 = 0;
    int pos[4] = {0, 1, 2, 3};
    while (n--) {
        int a, b, guess;
        cin >> a >> b >> guess;

        swap(pos[a], pos[b]);
        if (pos[guess] == 1) ++case1;
        else if (pos[guess] == 2) ++case2;
        else if (pos[guess] == 3) ++case3;
    }
    cout << max({case1, case2, case3});
}