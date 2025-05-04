#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    
    int n; cin >> n;
    int pos[n+1];
    string order[n+1];

    for (int i = 1; i <= n; i++) {
        // Get the position which shuffle to ai;
        int idx; cin >> idx;
        pos[idx] = i;
    }
    for (int idx = 1; idx <= n; idx++) {
        string cow; cin >> cow;
        // Reverse the shuffle;
        int start_pos = idx;
        start_pos = pos[start_pos];
        start_pos = pos[start_pos];
        start_pos = pos[start_pos];
        order[start_pos] = cow;
    }

    for (int i = 1; i <= n; i++) cout << order[i] << endl;
}
