#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool all_lower(int k, vector <int> a, vector <int> b) {
    for (int i = 0; i < k; i++) {
        if (a[i] > b[i]) return false;
    }
    return true;
}
bool all_higher(int k, vector <int> a, vector <int> b) {
    for (int i = 0; i < k; i++) {
        if (a[i] < b[i]) return false;
    }
    return true;
}

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    
    int k, n; cin >> k >> n;
    vector <vector <int>> cow_session(n+1);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            int cow; cin >> cow;
            cow_session[cow].push_back(j);
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (all_lower(k, cow_session[i], cow_session[j]) || all_higher(k, cow_session[i], cow_session[j]))
                ++cnt;
        }
    }

    cout << cnt;
}
