#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector <int> barn1(10), barn2(10);
set <int> readings;

void pour(int i, vector <int> a, vector <int> b, int milk_a, int milk_b) {
    for (int j = 0; j < a.size(); j++) {
        milk_a -= a[j];
        milk_b += a[j];

        vector <int> new_a = a;
        new_a.erase(begin(new_a) + j);

        vector <int> new_b = b;
        new_b.push_back(a[j]);

        if (i == 4) {
            readings.insert(milk_a + a[j]);
            return;
        }
        else {
            pour(i+1, new_b, new_a, milk_b, milk_a);
        }

        milk_a += a[j];
        milk_b -= a[j];
    }
}

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    
    for (auto &x : barn1) cin >> x;
    for (auto &x : barn2) cin >> x;

    pour(0, barn1, barn2, 1000, 1000);
    cout << readings.size();
}
