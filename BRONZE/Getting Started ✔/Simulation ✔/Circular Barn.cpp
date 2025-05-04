#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    
    int n; cin >> n;
    int room[n];

    for (int i = 0; i < n; i++) cin >> room[i];
    
    int shortest_dis = INT32_MAX;
    for (int choose = 0; choose < n; choose++) {
        int idx = choose + 1, step = 1, dis = 0;

        while (step <= n-1 && idx != choose) {
            if (idx > n-1) idx = 0;

            dis += room[idx] * step;

            ++step;
            ++idx;
        }

        shortest_dis = min(shortest_dis, dis);
    }

    cout << shortest_dis;
}

