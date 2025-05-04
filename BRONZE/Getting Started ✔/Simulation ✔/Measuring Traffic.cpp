#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    
    int n; cin >> n;
    int start[n], end[n];
    string condition[n];

    for (int i = 0; i < n; i++) cin >> condition[i] >> start[i] >> end[i];

    // Search from the mile N back to mile 1;
    int a = 0, b = 1e9 - 1;
    for (int i = n-1; i >= 0; i--) {
        if (condition[i] == "none") {
            a = max(a, start[i]);
            b = min(b, end[i]);
        } else if (condition[i] == "on") {
            a -= end[i];
            b -= start[i];
            // Prevent result from smaller than 0 numbers;
            a = max(a, 0);
        } else {
            a += start[i];
            b += end[i];
        }
    }

    cout << a << " " << b << endl;
    // Search from the mile 1 back to mile N;
    a = 0, b = 1e9 - 1;
    for (int i = 0; i < n; i++) {
        if (condition[i] == "none") {
            a = max(a, start[i]);
            b = min(b, end[i]);
        } else if (condition[i] == "on") {
            a += start[i];
            b += end[i];
        } else {
            a -= end[i];
            b -= start[i];
            // Prevent result from smaller than 0 numbers;
            a = max(a, 0);
        }
    }

    cout << a << " " << b;
}

