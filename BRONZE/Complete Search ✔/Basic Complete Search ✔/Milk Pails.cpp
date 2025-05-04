#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    
    int bucket1, bucket2, bucket3;
    cin >> bucket1 >> bucket2 >> bucket3;

    int ans = 0, curr_milk = 0;
    for (int x = 0; bucket1 * x <= bucket3; x++) {
        for (int y = 0; bucket2 * y <= bucket3; y++) {
            curr_milk = bucket1 * x + bucket2 * y;
            if (curr_milk <= bucket3)
                ans = max(ans, curr_milk);
        }
    }

    cout << ans;
}
