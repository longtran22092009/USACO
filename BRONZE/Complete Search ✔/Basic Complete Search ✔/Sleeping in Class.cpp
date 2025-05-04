#include <bits/stdc++.h>
using namespace std;
#define ll long long

set <int> findDivisor(int number) {
    set <int> result;
    for (int i = 1; i*i <= number; i++) {
        if (number % i == 0) {
            result.insert(i);

            result.insert(number/i);
        }
    }

    return result;
}

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);

    int T; cin >> T;
    while (T--) {
        int n, sum = 0; cin >> n;
        vector <int> sleep_time(n);
        for (auto &x : sleep_time) {
            cin >> x;
            sum += x;
        }
        set <int> divisors = findDivisor(sum);

        int ans = INT32_MAX;
        for (auto x : divisors) {
            int curr_num = sleep_time[0], cnt = 0;
            bool valid = true;

            for (int i = 1; i < n; i++) {
                if (curr_num < x && curr_num + sleep_time[i] > x) {
                    valid = false;
                    break;
                }
                if (curr_num + sleep_time[i] <= x) {
                    curr_num += sleep_time[i];
                    ++cnt;
                }
                else {
                    if (sleep_time[i] > x) {
                        valid = false;
                        break;
                    }
                    curr_num = sleep_time[i];
                }
            }

            if (valid) {
                ans = min(ans, cnt);
            }
        }

        if (sum == 0) cout << 0 << endl;
        else cout << ans << endl;
    }
}
