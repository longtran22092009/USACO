#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Cow {
    int start, end, buckets;
};

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    
    int n; cin >> n;
    vector <Cow> cow(n);

    for (Cow &c : cow) cin >> c.start >> c.end >> c.buckets;

    int ans = 0;
    for (int time = 1; time <= 1000; time++) {
        int curr_bucket = 0;
        for (auto c : cow) {
            if (c.start <= time && time <= c.end) 
                curr_bucket += c.buckets;
        }
        ans = max(ans, curr_bucket);
    }

    cout << ans;
}

