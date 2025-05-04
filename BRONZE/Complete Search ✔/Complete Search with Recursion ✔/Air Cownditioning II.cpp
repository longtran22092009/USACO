#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll N, M, minCost, stalls[101];

struct Cow {
    ll start, end, temperature;
};

struct Conditioner {
    ll cost, start, end, temperature;
};

bool check() {
    for (int i = 1; i <= 100; i++) {
        if (stalls[i] > 0) return false;
    }
    return true;
}

ll solve(ll i, vector <Conditioner> conditioners, ll cost, bool isUsed) {
    if (isUsed) {
        for (int idx = conditioners[i].start; idx <= conditioners[i].end; idx++) {
            stalls[idx] -= conditioners[i].temperature;
        }
    }

    if (i == M-1) {
        if (check()) return cost;
        return LONG_LONG_MAX;
    }

    ll used_case = solve(i+1, conditioners, cost + conditioners[i+1].cost, true);
    
    for (int idx = conditioners[i+1].start; idx <= conditioners[i+1].end; idx++) {
        stalls[idx] += conditioners[i+1].temperature;
    }

    ll unused_case = solve(i+1, conditioners, cost, false);

    return min(used_case, unused_case);
}

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    
    cin >> N >> M;
    vector <Cow> cows(N);
    vector <Conditioner> conditioners(M);

    for (auto &x : cows) {
        cin >> x.start >> x.end >> x.temperature;

        for (ll i = x.start; i <= x.end; i++) {
            stalls[i] += x.temperature;
        }
    }
    for (auto &y : conditioners) cin >> y.start >> y.end >> y.temperature >> y.cost;
    
    minCost = solve(-1, conditioners, 0, false);

    cout << minCost;
}
