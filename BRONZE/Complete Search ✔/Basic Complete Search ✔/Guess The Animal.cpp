#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);

    int n; cin >> n;
    vector <vector <string>> characteristics(n);

    for (int i = 0; i < n; i++) {
        string name; cin >> name;
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            string chars; cin >> chars;
            characteristics[i].push_back(chars);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Find the intersection of characteristics between two animal;
            int same = 0;
            for (auto chars_a : characteristics[i]) {
                for (auto chars_b : characteristics[j]) {
                    if (chars_a == chars_b) {
                        ++same;
                        break;
                    }
                }
            }

            ans = max(ans, same);
        }
    }

    cout << ans+1;
}
