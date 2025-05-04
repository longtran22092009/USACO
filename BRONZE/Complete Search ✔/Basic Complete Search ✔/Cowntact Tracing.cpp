#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Event {
    int time, xCow, yCow;
};

bool comp(Event &a, Event &b) {
    return a.time < b.time;
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    // Parse the input;
    int n, t; cin >> n >> t;
    string cowCondition; cin >> cowCondition;
    vector <Event> record(t);
    vector <bool> final_state(n);

    for (auto &x : record) cin >> x.time >> x.xCow >> x.yCow;
    sort(record.begin(), record.end(), comp);

    for (int i = 0; i < n; i++) {
        if (cowCondition[i] == '1') final_state[i] = true;
        else final_state[i] = false;
    }

    int possible_f0 = 0, min_k = t, max_k = -1;
    // Assume each cow is the patient-zero;
    for (int patient_zero = 0; patient_zero < n; patient_zero++) {
        bool valid = false;

        if (final_state[patient_zero]) {
            // Loop through k cases to see which will give the valid result;
            for (int k = 0; k <= t; k++) {
                vector <bool> state(n, false);
                state[patient_zero] = true;
                vector <int> k_time(n, k);

                for (auto event : record) {
                    int cow1 = event.xCow-1;
                    int cow2 = event.yCow-1;

                    /* Two cows who greet each other are infected 
                    * and still not realize that they are spreading the infection;
                    */  
                    if (state[cow1] && k_time[cow1] && state[cow2] && k_time[cow2]) {
                        --k_time[cow1];
                        --k_time[cow2];
                    } 
                    // Cow x is infected and still not realize it;
                    else if (state[cow1] && k_time[cow1]) {
                        --k_time[cow1];
                        state[cow2] = true;
                    } 
                    // Cow x is infected and still not realize it;
                    else if (state[cow2] && k_time[cow2]) {
                        --k_time[cow2];
                        state[cow1] = true;
                    } 
                }

                // Check if the result is valid;
                bool possible = true;
                for (int i = 0; i < n; i++) {
                    if (state[i] != final_state[i]) 
                        possible = false;
                }

                if (possible) {
                    valid = true;
                    if (k == t) max_k = t;
                    else {
                        if (k < min_k) min_k = k;
                        if (k > max_k) max_k = k;
                    }
                }
            }
        }
        
        if (valid) ++possible_f0;
    }
  
    cout << possible_f0 << " " << min_k << " ";
    if (max_k == t) cout << "Infinity";
    else cout << max_k;
}
