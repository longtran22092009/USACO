#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);

    string s; cin >> s;
    set <char> already_checked;

    int pairs = 0;
    for (int i = 0; i < s.size(); i++) {
        if (already_checked.count(s[i]) == 0) {
            set <char> inPair;
            for (int j = i+1; j < s.size(); j++) {
                if (s[j] == s[i]) break;
                if (inPair.count(s[j]) == 0) {
                    ++pairs;
                    inPair.insert(s[j]);
                } else {
                    --pairs;
                }
            }
        }
        already_checked.insert(s[i]);
    }

    cout << pairs/2;
}
