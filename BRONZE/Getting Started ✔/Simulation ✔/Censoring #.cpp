#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);

    string s, t;
    cin >> s >> t;

    // Save the character and check for each t.size() substring;
    string result; 

    for (auto c : s) {
        result.push_back(c);

        if (result.size() >= t.size() && result.substr(result.size() - t.size()) == t) {
            result.erase(result.size() - t.size(), t.size());
        }
    }

    cout << result;
}
