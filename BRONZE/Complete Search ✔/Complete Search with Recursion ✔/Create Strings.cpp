#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);

    string s; cin >> s;
    vector <string> ans;
    sort(s.begin(), s.end());
    ans.push_back(s);

    while (next_permutation(s.begin(), s.end())) {
        ans.push_back(s);
    }

    cout << ans.size() << endl;
    for (auto x : ans) cout << x << endl;
}
