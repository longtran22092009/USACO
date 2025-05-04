#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Milk {
    int who, type, time;
};

bool possible_bad(int N, vector <int> sickInf, set <int> milk_drunk) {
    for (int person = 1; person <= N; person++) {
        if (sickInf[person] == 0) continue;
        if (!milk_drunk.count(person)) return false;
    }
    return true;
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    int N, M, D, S;
    cin >> N >> M >> D >> S;
    vector <Milk> milkInf(D);
    vector <int> sickInf(N+1, 0);
    
    for (int i = 0; i < D; i++) {
        cin >> milkInf[i].who >> milkInf[i].type >> milkInf[i].time;
    }
    for (int i = 0; i < S; i++) {
        int who, times; cin >> who >> times;
        sickInf[who] = times;
    }

    vector <set <int>> milk_drunk(M+1);
    // Assume each type of milk is bad
    // count how many people drunk it at the time before they get sick;
    for (int milk_type = 1; milk_type <= M; milk_type++) {
        // Loop through information about which drunk at time by who;
        for (auto milk : milkInf) {
            // If it is the milk type assumed is bad;
            if (milk.type == milk_type) {
                // And if it drink at the time before who drinks it gets sick;
                if (milk.time < sickInf[milk.who] || sickInf[milk.who] == 0) {
                    milk_drunk[milk_type].insert(milk.who);
                }
            }
        }
    }

    int ans = 0;
    // Find the maximum number of medicine we need;
    for (auto people_sick : milk_drunk) {
        if (possible_bad(N, sickInf, people_sick))
            ans = max(ans, (int) people_sick.size());
    }

    cout << ans;
}
