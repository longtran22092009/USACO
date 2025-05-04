#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(vector <pair <string, string>> constraints, vector <string> cows) {
    for (auto it : constraints) {
        auto curr_pos = find(cows.begin(), cows.end(), it.first);
        auto before = (curr_pos != cows.begin())? curr_pos - 1 : curr_pos;
        auto after = (curr_pos != prev(cows.end()))? curr_pos + 1 : curr_pos;
        
        if (*before != it.second && *after != it.second) return false;
    }
    
    return true;
}

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    
    int n; cin >> n;
    vector <pair <string, string>> constraints(n);
    vector <string> cows = {"Beatrice", "Sue", "Belinda", "Bessie", "Betsy", "Blue", "Bella", "Buttercup"};
    sort(cows.begin(), cows.end());

    for (int i = 0; i < n; i++) {
        string a, tmp, b;
        cin >> a >> tmp >> tmp >> tmp >> tmp >> b;
        constraints[i] = {a, b};
    }

    do {
        if (check(constraints, cows)) {
            for (auto cow : cows) cout << cow << endl;
            return 0;
        }
    }
    while (next_permutation(cows.begin(), cows.end()));
}
